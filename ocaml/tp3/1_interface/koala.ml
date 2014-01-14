(***************************************************************************)
(*                                                                         *)
(*                       koala.ml in 1_interface                           *)
(*                       For Epitech's λ Knowledge Unit                    *)
(*                       Made by: David GIRON                              *)
(*                                                                         *)
(***************************************************************************)



type name      = string
type age       = int
type promo     = int
type graduated = bool

type koala     = (name * age * promo * graduated)


let create n a p g = (n, a, p, g)

let get_name     (n, _, _, _) = n
let get_age      (_, a, _, _) = a
let get_promo    (_, _, p, _) = p
let has_finished (_, _, _, g) = g

let print (n, a, p, g) =
  let text = if g then "graduated"
                  else "did not graduated yet"
  in Printf.printf "%s is %d years old, from promo %d and %s.\n" n a p text



(***************************************************************************)
