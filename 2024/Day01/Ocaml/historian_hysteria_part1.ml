let build_lists filename =
  let left_lst = ref [] in
  let right_lst = ref [] in
  let file_handler = open_in filename in
  try
    while true do
      let line = input_line file_handler in
      match List.filter (fun s -> s <> "") (String.split_on_char ' ' line) with
      | [x; y] ->
        left_lst := int_of_string x :: !left_lst;
        right_lst := int_of_string y :: !right_lst
      | _ -> failwith "Invalid file format"
    done;
    (!left_lst, !right_lst)
  with End_of_file ->
    close_in file_handler;
    (List.rev !left_lst, List.rev !right_lst)

let () =
  let left_lst, right_lst = build_lists "file.txt" in
  let sorted_left_lst = List.sort compare left_lst in
  let sorted_right_ls = List.sort compare right_lst in
  let diff_list = List.map2 (fun lhs rhs -> abs (rhs - lhs)) sorted_left_lst sorted_right_ls in
  let sum = List.fold_left (fun acc x -> acc + x) 0 diff_list in
  Printf.printf "diff sum = %d\n" sum;
