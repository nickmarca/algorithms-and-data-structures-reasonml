let add = (a, e) => {
  List.rev_append([e], a);
};

let rec helper = (~chunks=[], a: list('a), size: int) => {
  switch (a) {
  | [] => chunks
  | [head, ...rest] =>
    switch (chunks) {
    | [] => helper(~chunks=[[head]], rest, size)
    | [chead, ...crest] when List.length(chead) < size =>
      helper(~chunks=add(crest, add(chead, head)), rest, size)
    | _ => helper(~chunks=add(chunks, [head]), rest, size)
    }
  };
};

let chunk = (a, size) => {
  let r = helper(Array.to_list(a), size);
  let s = List.rev(List.map(i => List.rev(i), r));
  Array.of_list(List.map(i => Array.of_list(i), s));
};
