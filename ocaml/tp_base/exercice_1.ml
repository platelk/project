let exercice_1 = "Reussi !"
let exercice_2 = "Reussi aussi !"

(*
** Exo 4
*)

let a = 42 (* int *)
a;; (* int *)
let b = "suspens..."(* string *)
let c = ();; (* unit *)
let d = 42 + 0;; (* int *)
let e = 42.0 +. 0;; (* Error : +. = float->float->float *)
let f = 30 and g = 12;; (* int, int *)
let h = f + g;; (* int *)
let i = let j = 50 and k = 8 in j - k;; (* int *)
let l = 42 in let m = l - 42 in l + m;; (* int *)
let n = 42 and o = n - 42 in n + o;; (* Error *)
(*
** Exo 5
*)

let fonction_p = fun a b -> a + b;; (* int->int->int *)
let fonction_q a b = a + b;; (* int->int->int *)
fonction_q 21 21;; (* int = 42  *)
fonction_q;; (* Error ? Non renvoie une fonction int->int->int *)
let fonction_r () = 42;; (* unit->int *)
let fonction_s a = 42;; (* 'a -> int *)
let fonction_t a = a;; (* 'a -> 'a *)
let fonction_u a b = a b;; (* let f a = fun b -> a b;; == ('a -> 'b)-> 'a -> 'b *)
let fonction_v a b c = a b c;; (* let f a = fun b -> fun c = a b c *)
let fonction_w a b c = a (b c);;
let fonction_x () = let a = 42 in let b = 42 in a - b + 42;; (* unit -> int *)
let y = "a" in let fonction_z a b = b ^ y in fonction_z;; (* unit -> string -> string *)
let incr a = a + 1;;

(*
** Exo 8
*)

let f a b c = (a c (b c));;

(*
** Exo 9
*)

let rec fact a = if a == 1 then 1 else a * fact(a - 1);;
let fac n = let rec fact_term a acc = if a == 1 then acc else fact_term (a-1) (acc*a) in fact_term n 1;;
