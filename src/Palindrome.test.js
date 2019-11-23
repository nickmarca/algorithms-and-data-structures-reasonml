const { isPalindrome, isPalindrome2 } = require("./Palindrome.bs");

describe("Palindromes", () => {

  test("is palindrome fn: negative case", () => {
    const a = "abc";

    expect(isPalindrome(a)).toBe(false);
  });

  test("is palindrome fn: positive case", () => {
    const a = "abba";

    expect(isPalindrome(a)).toBe(true);
  });

  test("is palindrome fn: negative case", () => {
    const a = "abc";

    expect(isPalindrome2(a)).toBe(false);
  });

  test("is palindrome fn: positive case", () => {
    const a = "abba";

    expect(isPalindrome2(a)).toBe(true);
  });

  test("is palindrome fn: positive case", () => {
    const a = "12321";

    expect(isPalindrome2(a)).toBe(true);
  });

  test("is palindrome fn: positive case", () => {
    const a = "1221";

    expect(isPalindrome2(a)).toBe(true);
  });
});
