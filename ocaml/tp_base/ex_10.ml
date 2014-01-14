let rec fib a = match a with
  | 0 -> 0
  | 1 -> 1
  | _ -> (fib (a-1)) + (fib (a-2))


let fib2 i =
  let rec fib_aux n =
    if n == 1
    then
      (1,0)
    else
      let a = fib_aux (n-1) in (((fst a) + (snd a)), (fst a))
  in
  let b = fib_aux (i-1) in ((fst b) + (snd b))

let fib3 i = function
  let rec fib_aux n a b =
    if n == 1
    then
      a + b
    else
      fib_aux (n-1) (a + b) a
  in
  if (i == 0)
  then
    0
  else
    fib_aux i 1 0
