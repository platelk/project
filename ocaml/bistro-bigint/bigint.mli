(*    **************	*)
(*			*)
(*     Module bigint	*)
(*  create by platel_k	*)
(*			*)
(*    **************	*)

(* Type use in module *)
type bigint
type base = Binary | Octal | Decimal | Hexadecimal

(*
  Convert a string to a bigint :
  "0x" for Hexa with ignore case
  "0b" for binary
  "0"  for octal
  else is treat as decimal
*)
val bigint_of_string	: string -> bigint

(*
  Convert a bigint to string in decimal base
*)
val string_of_bigint	: bigint -> string

 (*
   Convert a bigint to string in  base specified base the parameter
 *)
 (* val string_of_bigint_base	: bigint -> base -> string *)

 (*
   Operation on bigint
 *)
 (* val add	: bigint -> bigint -> bigint *)
 (* val sub	: bigint -> bigint -> bigint *)
 (* val mul	: bigint -> bigint -> bigint *)
 (* val div	: bigint -> bigint -> bigint *)
 (* val modulo	: bigint -> bigint -> bigint *)
