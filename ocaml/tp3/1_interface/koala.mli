(***************************************************************************)
(*                                                                         *)
(*                      koala.mli in 1_interface                           *)
(*                      For Epitech's λ Knowledge Unit                     *)
(*                      Made by: David GIRON                               *)
(*                                                                         *)
(***************************************************************************)



type name      = string
type age       = int
type promo     = int
type graduated = bool

type koala     = (name * age * promo * graduated)


val create : name -> age -> promo -> graduated -> koala

val get_name     : koala -> name
val get_age      : koala -> age
val get_promo    : koala -> promo
val has_finished : koala -> graduated

val print : koala -> unit



(***************************************************************************)
