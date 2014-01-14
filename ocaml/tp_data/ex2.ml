let rec iter f l = match l with
  | [] -> ()
  | first::rest ->
    begin
      f first;
      iter f rest
    end

exception My_except

let list_mul l =
  let rec list_mul_aux l a = match l with
    | [] -> a
    | first::rest ->
      if first == 0
      then
	raise My_except
      else
	list_mul_aux rest (a*first)
  in
  try
    list_mul_aux l 1
  with
  | My_except -> 0
  | _ -> 0
