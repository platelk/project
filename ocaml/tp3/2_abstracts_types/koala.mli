(****************************************************************************)
(*                                                                          *)
(*                         koala.mli in abstracts_types                     *)
(*                         For Epitech's λ Knowledge Unit                   *)
(*                         Made by: David GIRON                             *)
(*                                                                          *)
(****************************************************************************)



type t


val create : string -> int -> int -> bool -> t

val get_name     : t -> string
val get_age      : t -> int
val get_promo    : t -> int
val has_finished : t -> bool

val print : t -> unit



(****************************************************************************)
