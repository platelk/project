module Case : sig
  type state = Close | Open
  type case

  val length	 : case -> int
  val get	 : case -> int -> case
  val get_open	 : case -> int -> case
  val get_close	 : case -> int -> case

  val set	 : case -> int -> case -> state -> unit
  val equal	 : case -> case -> bool
  val inter	 : case -> case -> bool
  val inter_idx	 : case -> case -> int
  val open_door  : case -> int -> unit
  val close_door : case -> int -> unit
  val create	 : int -> case

  val nb_open	 : case -> int
  val nb_close	 : case -> int
  val print_case : case -> unit

  val change_state_door : state -> case -> int -> unit
  val get_idx_open	 : case -> int -> int
  val get_idx_close	 : case -> int -> int

  exception Invalid_case
  exception Not_connect_case

end

type labyrinthe

val create : int -> int -> int -> labyrinthe
val print_lab :int -> int -> labyrinthe -> unit

val get_case : labyrinthe -> int -> int -> Case.case
