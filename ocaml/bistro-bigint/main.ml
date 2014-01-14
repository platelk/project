let main () =
  let my_nb = Bigint.bigint_of_string "155" in
  begin
    print_string "test";
    print_string (Bigint.string_of_bigint my_nb);
  end

let _ = main ()
