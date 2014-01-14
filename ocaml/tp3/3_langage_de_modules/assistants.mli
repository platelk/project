(****************************************************************************)
(*                                                                          *)
(*                     assistants.mli in langage_de_module                  *)
(*                     For Epitech's λ Knowledge Unit                       *)
(*                     Made by: David GIRON                                 *)
(*                                                                          *)
(****************************************************************************)


module type ASSISTANT =
  sig

    type t

    val new_assistant : string -> int -> t

    val get_name : t -> string
    val get_promo : t -> int

    val print : t -> unit

  end


module Koala : ASSISTANT

module Astek : ASSISTANT
