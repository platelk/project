module Case : sig
  type state = Close | Open
  type case

  val length	  : case -> int
  val get	  : case -> int -> case
  val get_open	  : case -> int -> case
  val get_close	  : case -> int -> case

  val set	  : case -> int  -> case -> state -> unit
  val equal	  : case -> case -> bool
  val inter	  : case -> case -> bool
  val inter_idx	  : case -> case -> int
  val inter_state : case -> case -> state
  val open_door   : case -> int  -> unit
  val close_door  : case -> int  -> unit
  val create	  : int -> case

  val nb_open	  : case -> int
  val nb_close	  : case -> int
  val print_case  : case -> unit

  val change_state_door  : state -> case -> int -> unit
  val get_idx_open	 : case  -> int  -> int
  val get_idx_close	 : case  -> int  -> int

  val get_list_state	 : case -> state list

  exception Invalid_case
  exception Not_connect_case

end = struct

  type state = Close | Open

  type case =
  | Case of (case ref * state) array ref
  | None

  exception Invalid_case
  exception Not_connect_case

  (* Function implementation *)

  let length case = match case with
    | Case(a) -> Array.length !a
    | None    -> 0

  let get_idx case i = match case with
    | Case(a) -> Array.get !a i
    | None    -> raise Invalid_case

  let get case i = !(fst (get_idx case i))

  let rec get_state f state case i =
    if i >= (length case)
    then
      raise Not_found
    else
      match (get_idx case i) with
      | ({ contents = None }, _) -> get_state f state case (i + 1)
      | (c, status) ->
  	if status = state
  	then
  	  f (i, !c)
  	else
  	  get_state f state case (i + 1)

  let get_list_state case =
    let rec get_list_state_rec case i l =
      if i > length case
      then
	l
      else
	get_list_state_rec case (i + 1) ((snd (get_idx case i))::l)
    in
    get_list_state_rec case 0 []

  let get_idx_open = get_state fst Open
  let get_open = get_state snd Open

  let get_idx_close = get_state fst Close
  let get_close = get_state snd Close

  let set case i item state = match case with
    | Case(a) -> Array.set !a i (ref item, state)
    | None    -> raise Invalid_case

  let equal case1 case2 = match case1, case2 with
    | Case(a), Case(b)  -> a == b
    | None, None	-> true
    | _, _		-> false

  let inter_idx case1 case2 =
    let rec inter_rec case1 case2 i =
      if (length case1) <= i
      then
  	-1
      else
  	if equal (get case1 i) case2
  	then
  	  i
  	else
  	  inter_rec case1 case2 (i + 1)
    in
    inter_rec case1 case2 0

  let inter case1 case2 = (inter_idx case1 case2) >= 0

  let inter_state case1 case2 = snd (get_idx case1 (inter_idx case1 case2))

  let change_one_side_state state case i = match case with
    | None -> raise Invalid_case
    | _    -> set case i (get case i) state

  let change_state_door state case i =
    let linked = get case i in
    let link_idx = inter_idx linked case in
    begin
      if link_idx < 0
      then
	raise Not_connect_case
      else
	change_one_side_state state linked link_idx;
      change_one_side_state state case i;
    end

  let open_door = change_state_door Open

  let close_door = change_state_door Close

  let create i =
    Case (ref (Array.make i (ref None, Close)))

  let nb_state state case =
    let rec nb_state case state i acc =
      if (length case) <= acc
      then
	i
      else
	match (get_idx case acc) with
	| (_, status) ->
	  if status = state
	  then
	    nb_state case state (i + 1) (acc + 1)
	  else
	    nb_state case state i (acc + 1)
    in
    nb_state case state 0 0

  let nb_open = nb_state Open
  let nb_close = nb_state Close

  let print_state c = match !c with
    | Case(d) -> print_string "Case"
    | None -> print_string "None"

  let print_one_case i (c,s) =
    begin
      print_int i;
      print_string " : [";
      print_string "] ";
      print_state c;
      print_string " ";
      if s = Open
      then
	print_string "Open"
      else
	print_string "Close";
      print_string "\n";
    end

  let print_case a = match a with
    | Case(t) -> Array.iteri print_one_case !t
    | None    -> ()

end

(* Labyrinthe module *)

type labyrinthe = (Case.case array * int * int)

type node =
| Node of (int * int * int)
| Empty

let compare_weight (a,_) (b,_) =
  match a,b with
  | (-1),(-1) -> 0
  | (-1),_    -> (1)
  | _, (-1)   -> -1
  | a, b      -> compare a b

let check tab =
  let rec check_rec tab a i =
    if (Array.length tab) <= i
    then
      true
    else
      if (Array.get tab i) != a
      then
	false
      else
	check_rec tab a (i + 1)
  in
  check_rec tab (Array.get tab 0) 0

let link_one_square tab height width i a =
  begin
    if ((i + 1) mod width) != 0
    then
      begin
	Case.set a 1 (Array.get tab (i + 1)) Case.Close;
	Case.set (Array.get tab (i + 1)) 3 a Case.Close;
      end
    else
      ();
    if (i + width) < (height * width)
    then
      begin
	Case.set a 2 (Array.get tab (i + width)) Case.Close;
	Case.set (Array.get tab (i + width)) 0 a Case.Close;
      end
    else
      ()
  end

let get_color col_tab i idx width =
  match idx with
  | 0 -> Array.get col_tab (i - width)
  | 1 -> Array.get col_tab (i + 1)
  | 2 -> Array.get col_tab (i + width)
  | 3 -> Array.get col_tab (i - 1)
  | _ -> -1

let is_in_color col_tab i idx width =
  (get_color col_tab i idx width) = (Array.get col_tab i)


let set_color_square col_tab i idx width =
  let col = get_color col_tab i idx width in
  let to_col = Array.get col_tab i in
  Array.iteri (fun i a -> if a = col then Array.set col_tab i to_col else ()) col_tab

(* Module function *)

let create height width size =
  let tab = Array.init (height * width) (fun a -> Case.create size) in
  let col_tab = Array.init (height * width) (fun a -> a) in
  let rec open_rand_door case i =
    try
      let idx = Case.get_idx_close case (Random.int size) in
      if is_in_color col_tab i idx width
      then
	()
      else
	begin
	  Case.open_door case idx;
	  set_color_square col_tab i idx width;
	end
    with x -> ()
  in
  let link_one = link_one_square tab height width in
  let link_tab tab = Array.iteri link_one tab in
  let rec create_lab tab =
    if (check col_tab) = true
    then
      ()
    else
      let _ = Array.iteri (fun i a -> open_rand_door a i) tab in
      create_lab tab
  in
  begin
    Random.self_init ();
    link_tab tab;
    create_lab tab;
    (tab, height, width);
  end

let get_case (lab,height,width) x y =
  if ((x * width) + y) < (Array.length lab)
  then
    Array.get lab ((x * width) + y)
  else
    raise (Invalid_argument "index out of range")
let solve (lab,height,width) (x_start,y_start) (x_fin,y_fin) =
  let weight_map = (Array.make_matrix height width (-1)) in
  let set_weight case (x,y) weight =
    if x < height && y < width &&
      ((weight_map.(x).(y)) > weight || (weight_map.(x).(y)) < 0)
    then
      try
	if (Case.inter_state (get_case (lab,height,width) x y) case) = Case.Open
	then
	  begin
	    weight_map.(x).(y) <- weight;
	    weight;
	  end
	else
	  -1
      with x -> -1
    else
      -1
  in
  let rec find_path (x,y) weight =
    let _ = solve (x,y) (x+1,y) (weight + 1) in
    let _ = solve (x,y) (x-1,y) (weight + 1) in
    let _ = solve (x,y) (x,y+1) (weight + 1) in
    solve (x,y) (x,y-1) (weight + 1);
  and
      solve (x_prev,y_prev) (x,y) weight =
    try
      if x >= height || y >= width || (set_weight (get_case (lab,height,width) x_prev y_prev) (x,y) weight) < 0
      then
	weight
      else
	find_path (x,y) weight
    with x -> weight
  in
  let get_weight (x_prev,y_prev) (x,y) =
    if (x >= height || y >= width || x < 0 || y < 0)
    then
      (-1,(x,y))
    else
      if (Case.inter_state (get_case (lab,height,width) x y) (get_case (lab,height,width) x_prev y_prev)) = Case.Open
      then
	(weight_map.(x).(y),(x,y))
      else
	(-1,(x,y))
  in
  let get_best_pos (x,y) =
    snd (List.hd (List.sort compare_weight (get_weight (x,y) (x+1,y)::get_weight (x,y) (x-1,y)::get_weight (x,y) (x,y+1)::get_weight (x,y) (x,y-1)::[])))
  in
  let rec resolve (x,y) acc =
    if x = x_fin && y = y_fin
    then
      (y,x)::acc
    else
      resolve (get_best_pos (x,y)) ((y,x)::acc)
  in
  let _ = weight_map.(x_fin).(y_fin) <- 0 in
  let _ = find_path (x_fin,y_fin) 0 in
  List.rev (resolve (x_start,y_start) [])

let print_lab (tab,height,width) =
  let print_one_case i case =
    begin
      begin
	try
	  if (Case.get_idx_open case 2) = 2
	  then
	    print_string " "
	  else
	    print_string "_"
	with x -> print_string "_";
      end;
      begin
	try
	  if (Case.get_idx_open case 1) = 1
	  then
	    print_string " "
	  else
	    print_string "|";
	with x -> print_string "|";
      end;
      if ((i+1) mod width) = 0 && (i+1) < (height * width)
      then
	print_string "\n|"
      else
	();
    end
  in
  begin
    print_string (String.make (width * 2) '_');
    print_string "\n|";
    Array.iteri print_one_case tab;
    print_string "\n";
  end
