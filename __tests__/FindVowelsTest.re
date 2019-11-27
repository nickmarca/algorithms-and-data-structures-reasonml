open Jest;

describe("FindVowels", () => {
  open Expect;

  test("hello world", () =>
    expect(FindVowels.run("hello world")) |> toBe(3)
  );

  test("Hi, my name is nicholas", () =>
    expect(FindVowels.run("Hi, my name is nicholas")) |> toBe(7)
  );
});