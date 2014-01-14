type frac =
  Undef
| Frac of (int * int)

let frac_of_int n = (Frac (n,1))
let get_num = function
  | Undef -> failwith "fail"
  | Frac (a,b) -> a

let get_denom = function
  | Frac (a,b) -> b
  | Undef -> failwith "fail"

let print_frac = function
  | Frac (a,b) ->
    if b == 1
    then
      begin
	print_int(a);
	print_endline("")
      end
    else
      begin
	print_int(a);
	print_string("/");
	print_int(b)
      end
  | _ -> print_endline("NaN")

let plus a b = Frac ((((get_num a) * (get_denom b)) + ((get_num b) * (get_denom a))), ((get_denom a) * (get_denom b)))

let div a b = Frac (((get_num a) * (get_denom b)), ((get_num b) * (get_denom a)))


(* plus (div (frac_of_int 3) (frac_of_int 6)) (div (frac_of_int 5) (frac_of_int 4)) *)
