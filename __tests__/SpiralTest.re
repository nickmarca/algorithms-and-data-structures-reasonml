open Jest;

let spiral3 = [|
  [|Some(1), Some(2), Some(3)|],
  [|Some(8), Some(9), Some(4)|],
  [|Some(7), Some(6), Some(5)|],
|];

describe("FindVowels", () => {
  open Expect;

  test("Spiral 3", () =>
    expect(Spiral.run(3)) |> toEqual(spiral3)
  );

  test("dumb", () => {
    Spiral.run(6);
    expect(1 + 1) |> toBe(2);
  });

  test("Hi, my name is nicholas", () =>
    expect(FindVowels.run("Hi, my name is nicholas")) |> toBe(7)
  );
});