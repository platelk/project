(*    **************	*)
(*			*)
(*     Module bigint	*)
(*  create by platel_k	*)
(*			*)
(*    **************	*)

type base = Binary | Octal | Decimal | Hexadecimal
type bigint = (int list * bool)

(* Utils *)


let bigint_of_int nb =
  let rec bigint_of_int_rec nb res sign =
    if nb = 0
    then
      (List.rev res, sign)
    else
      bigint_of_int_rec (nb / 10) ((nb mod 10)::res) sign
  in
  if nb < 0
  then
    bigint_of_int_rec nb [] false
  else
    bigint_of_int_rec nb [] true

let rec add_zero res nb_zero =
  if nb_zero = 0
  then
    res
  else
    add_zero (0::res) (nb_zero - 1)

let value_of_char c base =
  try
    match base with
    | Binary      -> bigint_of_int (String.index "01" c)
    | Octal       -> bigint_of_int (String.index "01234567" c)
    | Decimal     -> bigint_of_int (String.index "0123456789" c)
    | Hexadecimal -> bigint_of_int (String.index "0123456789abcdef" (Char.lowercase c))
  with Not_found ->
    failwith "Undefined character"

let length_of_base base = match base with
  | Binary      -> [2]
  | Octal       -> [8]
  | Decimal     -> [0;1]
  | Hexadecimal -> [6;1]

(* In construct !!! *)


let rec del_useless_zero nb =
  match nb with
  | []   -> nb
  | h::q ->
    if h != 0 || (List.length nb) = 1
    then
      nb
    else
      del_useless_zero q

let return_list l = l

let rest_of_number nb = match nb with
  | []   -> []
  | h::q -> q

(* Function to specialise *)

let rec operation_rec f f_to_nb2  min_length_nb2 nb1 nb2 res =
    if List.length nb1 = 0 && List.length nb2 <= min_length_nb2
    then
      del_useless_zero res
    else
      match res with
      | []   -> operation_rec f f_to_nb2  min_length_nb2 (rest_of_number nb1) (f_to_nb2 nb2) (f nb1 nb2 [] 0)
      | h::q -> operation_rec f f_to_nb2  min_length_nb2 (rest_of_number nb1) (f_to_nb2 nb2) (f nb1 nb2 q h)

let calc f nb1 nb2 res hr =
    match nb1, nb2 with
    | h1::q1, h2::q2      -> (((f h1 h2) + hr) / 10)::(((f h1 h2) + hr) mod 10)::res
    | [], h2::q2	  -> ((f h2 hr) / 10)::((h2 + hr) mod 10)::res
    | h1::q1, []	  -> ((f h1 hr) / 10)::((h1 + hr) mod 10)::res
    | [], []		  -> hr::res

let sup (nb1,s_nb1) (nb2,s_nb2) =
  let rec sup_rec nb1 nb2 = match nb1, nb2 with
    | h1::q1, h2::q2 ->
      if h2 = h1
      then
	sup_rec q1 q2
      else
	h1 > h2
    | _, _  -> false
  in
  let length_nb1 = (List.length nb1) in
  let length_nb2 = (List.length nb2) in
  if length_nb1 = length_nb2
  then
    sup_rec (List.rev nb1) (List.rev nb2)
  else
    length_nb1 > length_nb2

let inf nb1 nb2 = not (sup nb1 nb2)


(* Addition *)

let add (nb1,s_nb1) (nb2,s_nb2) =
  let add_to_res = calc (+) in
  let add_test = operation_rec add_to_res rest_of_number 0 in
  match s_nb1,s_nb2 with
  | true, false -> sub (nb2,false) (nb1,false)
  | false, true -> sub (nb1,false) (nb2,false)
  | _, _        -> ((List.rev (del_useless_zero (add_test nb1 nb2 []))), s_nb1)

(* multiplication *)

let mul (nb1,s_nb1) (nb2,s_nb2) =
  let mul_to_res = calc ( * ) in
  let rec mul_rec = operation_rec mul_to_res return_list 1 in
  let rec mul_iter nb1 nb2 res i =
    match nb2 with
    | []   -> res
    | h::q ->
      let (result,sign) = add ((add_zero (List.rev (mul_rec nb1 [h] [])) i),true) (res,true) in
      mul_iter nb1 q result (i + 1)
  in
  ((mul_iter nb1 nb2 [] 0), (s_nb1 && s_nb2))

(* Soustraction *)

let sub (nb1,s_nb1) (nb2,s_nb2) =
  let ret_sub nb = match nb with
    | []   -> []
    | h::q ->
      if h < 0
      then
	1::(10 + h)::q
      else
	0::nb
  in
  let sub_to_res nb1 nb2 res hr =
    match nb1, nb2 with
    | h1::q1, h2::q2      -> ret_sub ((h1 - (h2 + hr))::res)
    | [], h2::q2	  -> ret_sub (((h2 - hr) mod 10)::res)
    | h1::q1, []	  -> ret_sub (((h1 - hr) mod 10)::res)
    | [], []		  -> hr::res
  in
  let sub_rec = operation_rec sub_to_res rest_of_number 0 in
  match s_nb1,s_nb2 with
  | false,true -> add (nb1,false) (nb2,false)
  | true,false -> add (nb1,true) (nb2,true)
  | _, _       ->
    if (sup (nb1,s_nb1) (nb2,s_nb2))
    then
      ((List.rev (del_useless_zero (sub_rec nb1 nb2 []))), s_nb1)
    else
      ((List.rev (del_useless_zero (sub_rec nb2 nb1 []))), (not s_nb1))

(* Division *)
let useless_zero n = match n with
  | [0] -> []
  | _   -> n

let div_calc f (nb1,s_nb1) (nb2,s_nb2) =
  let rec find_one sub_nb nb2 compt acc =
    if (sup acc (sub_nb,true)) = false
    then
      find_one sub_nb nb2 (compt + 1) (add nb2 acc)
    else
      ((compt - 1), (sub (sub_nb,true) (sub acc nb2)))
  in
  let rec create_sub_nb nb1 nb2 sub_nb = match nb1 with
    | h::q ->
      if (sup nb2 (sub_nb,true)) = false
      then
	(sub_nb,nb1)
      else
	create_sub_nb q nb2 (h::sub_nb)
    | [] -> (sub_nb,[])
  in
  let rec div_rec f nb1 nb2 (res,rest) =
    let (sub_nb, r) = (create_sub_nb nb1 nb2 rest) in
    let (result,(div_rest,sign)) = (find_one sub_nb nb2 0 ([],true)) in
    if List.length nb1 = 0
    then
      f (res,rest)
    else
      div_rec f r nb2 ((result::res),(useless_zero div_rest))
  in
  if (List.hd nb2) = 0
  then
    failwith "Divid by zero"
  else
    ((div_rec f (List.rev nb1) (nb2,true) ([],[])), (s_nb1 && s_nb2))

let div nb1 nb2 = div_calc fst nb1 nb2

let modulo nb1 nb2 = div_calc snd nb1 nb2

(* Utils *)

let pow nb p =
  let rec pow_rec nb p acc =
    if p = 0
    then
	acc
    else
      pow_rec nb (p - 1) (mul acc nb)
  in
  pow_rec nb p ([1],true)

let bigint_of_string str =
  let define_sign str =
    if (String.get str 0) = '-'
    then
      (true,(String.sub str 1 ((String.length str) - 1)))
    else
      (false,str)
  in
  let define_base s =
    if (String.get s 0) = '0'
    then
      match (String.get s 1) with
      | 'b' -> (Binary, "0b", 2)
      | 'x' -> (Hexadecimal, "0x", 2)
      | _   -> (Octal, "0o", 1)
    else
      (Decimal, "", 0)
  in
  let rec bigint_of_string_rec s i base stop nb power sign =
    if i < stop
    then
      ((fst nb),sign)
    else
      bigint_of_string_rec s (i - 1) base stop (add (mul (value_of_char s.[i] base) (pow ((length_of_base base),true) power)) nb) (power + 1) sign
  in
  let (sign,num) = (define_sign str) in
  let (base, pref, idx) = (define_base num) in
  bigint_of_string_rec num (String.length num - 1) base idx ([],true) 0 sign

(* let string_of_bigint nb = *)
