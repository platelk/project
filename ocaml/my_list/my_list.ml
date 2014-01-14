type 'a my_list =
| Item of ('a * 'a my_list)
| Empty

let length l =
  let rec length_aux l i = match l with
    | Empty	-> i
    | Item(a,b) -> length_aux b (i+1)
  in
  length_aux l 0

let hd l = match l with
  | Empty     -> failwith "hd"
  | Item(a,b) -> a

let tl l = match l with
  | Empty     -> failwith "tl"
  | Item(a,b) -> b

let rec nth l n =
if n < 0
then
  invalid_arg "List.nth"
else
  match l with
  | Empty     -> failwith "nth"
  | Item(a,b) ->
    if n == 0
    then
      a
    else
      nth b (n-1)

let rev list =
  let rec rev_aux l acc = match l with
    | Empty      -> acc
    | Item (a,b) -> rev_aux b (Item (a,acc))
  in
  match list with
  | Empty -> Empty
  | Item (i,j) -> rev_aux j (Item (i, Empty))

let append la lb =
  let rec append_list l lc = match l with
    | Empty     -> rev lc
    | Item(a,b) -> append_list b (Item (a, lc))
  in
  append_list lb (rev la)


let rev_append la lb =
  let rec append_list l lc = match l with
    | Empty     -> rev lc
    | Item(a,b) -> append_list b (Item (a, lc))
  in
  append_list lb la

let concat l =
  let rec concat_aux l acc = match l with
    | Empty      -> acc
    | Item (a,b) -> concat_aux b (append acc a)
  in
  concat_aux l Empty

let flatten l =
  let rec concat_aux l acc = match l with
    | Empty      -> acc
    | Item (a,b) -> concat_aux b (append acc a)
  in
  concat_aux l Empty

let rec iter f l = match l with
  | Empty	-> ()
  | Item (a,b)  ->
    begin
      f a;
      iter f b
    end

let map f l =
  let rec map_aux f l acc = match l with
  | Empty	-> acc
  | Item (a,b)  -> map_aux f b (Item((f a), acc))
  in
  map_aux f l (Empty)

let rec fold_left f a b = match b with
  | Empty	-> a
  | Item(i,j)	-> fold_left f (f a i) j

let rec for_all p a = match a with
  | Empty	-> true
  | Item(i,j)	->
    if (p i) = false
    then
      false
    else
      for_all p j

let rec exists p a = match a with
  | Empty	-> false
  | Item(i,j)	->
    if (p i) == true
    then
      true
    else
      exists p j

let rec mem a l = match l with
  | Empty	-> false
  | Item(i,j)	->
    if i = a
    then
      true
    else
      mem a j

let rec memq a l = match l with
  | Empty	-> false
  | Item(i,j)	->
    if i == a
    then
      true
    else
      memq a j

let filter p l =
  let rec filter_aux p l acc = match l with
    | Empty	-> (rev acc)
    | Item(i,j) ->
      if (p i) = true
      then
	filter_aux p j (Item(i, acc))
      else
	filter_aux p j acc
  in
  filter_aux p l (Empty)

let rec assoc a l = match l with
  | Empty -> raise Not_found
  | Item(i,j) ->
    if a = (fst i)
    then
      snd i
    else
      assoc a j

let rec mem_assoc a l = match l with
  | Empty -> false
  | Item(i,j) ->
    if a = (fst i)
    then
      true
    else
      mem_assoc a j

let split l =
  let rec split_aux l acc_a acc_b = match l with
    | Empty	-> ((rev acc_a),(rev acc_b))
    | Item(a,b) -> split_aux b (Item((fst a), acc_a)) (Item((snd a), acc_b))
  in
  split_aux l Empty Empty

(* Bonus *)

let rec iter2 f l1 l2 = match l1,l2 with
  | Empty,Empty	-> ()
  | Item (a,b),Item(c,d)  ->
    begin
      f a c;
      iter2 f b d
    end
  | _ -> invalid_arg "invalid arg"

let map2 f l1 l2 =
  let rec map_aux f l1 l2 acc = match l1,l2 with
  | Empty,Empty		  -> acc
  | Item (a,b),Item(c,d)  -> map_aux f b d (Item((f a c), acc))
  | _			  -> invalid_arg "invalid arg"
  in
  map_aux f l1 l2 (Empty)

let rec fold_right f l b = match l with
  | Empty -> b
  | Item (i,j) -> fold_right f j (f i b)

let partition p l =
  let rec partition_aux p l acc1 acc2 = match l with
    | Empty -> (acc1,acc2)
    | Item(i,j) ->
      if (p i) = true
      then
	partition_aux p j (Item(i,acc1)) acc2
      else
	partition_aux p j acc1 (Item(i,acc2))
  in
  partition_aux p l Empty Empty

let rec mem_assq a l = match l with
  | Empty -> false
  | Item(i,j) ->
    if a == (fst i)
    then
      true
    else
      mem_assq a j

let remove_assoc p l =
  let rec remove_assoc_aux p l acc = match l with
    | Empty	-> acc
    | Item(a,b) ->
      if p = (fst a)
      then
	(append acc b)
      else
	remove_assoc_aux p b (Item(a, acc))
  in
  remove_assoc_aux p l Empty

let merge p l1 l2 =
  let rec merge_rec p l res = match l with
    | (Item(a,c),Item(b,d)) ->
      if (p a b) < 0
      then
	merge_rec p (c,(Item (b,d))) (Item (a,res))
      else
	merge_rec p ((Item(a,c)),d) (Item(b,res))
    | (Empty, Item(a,b)) -> merge_rec p (Empty, b) (Item(a,res))
    | (Item(a,b), Empty) -> merge_rec p (Empty, b) (Item(a,res))
    | _ -> rev res
  in
  merge_rec p (l1,l2) Empty

let scinder l =
  let rec scinder_rec l (a,b) = match l with
    | Empty -> (a,b)
    | Item(c,d) -> scinder_rec d (b,Item(c,a))
  in
  scinder_rec l (Empty,Empty)

let sort p l  =
  let rec scinder_rec_all p (c,d) =
    if (length c) = 1
    then
      merge p c d
    else
      merge p (scinder_rec_all p (scinder c)) (scinder_rec_all p (scinder d))
  in
  scinder_rec_all p (scinder l)

let stable_sort p l  =
  let rec scinder_rec l a = match l with
    | Empty -> (a,l)
    | Item(c,d) ->
      if (length l) < (length a)
      then
	(a,l)
      else
	scinder_rec d (Item(c,a))
  in
  let rec scinder_rec_all p (c,d) =
    if (length c) = 1
    then
      merge p c d
    else
      merge p (scinder_rec_all p (scinder_rec c Empty)) (scinder_rec_all p (scinder_rec d Empty))
  in
  scinder_rec_all p (scinder l)

let combine l1 l2 =
  let rec combine_rec l1 l2 acc = match l1,l2 with
    | Empty,Empty	  -> acc
    | Item(a,b),Item(c,d) -> combine_rec b d (Item((a,c),acc))
    | _			  -> invalid_arg "invalid arg"
  in
  combine_rec l1 l2 Empty
