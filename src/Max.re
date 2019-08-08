let rec max = xs => {
  switch (xs) {
  | [x] => x
  | [x, y, ...rest] =>
    max(
      List.rev_append(
        if (x > y) {
          [x];
        } else {
          [y];
        },
        rest,
      ),
    )
  | _ => 0
  };
};
