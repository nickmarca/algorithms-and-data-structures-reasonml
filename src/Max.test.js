const { max } = require('./Max.bs');
const { toList } = require('./Helpers.bs');

describe("Max", () => {
  test('CASE 1', () => {
    const s = [1, 2, 3];

    expect(max(toList(s))).toEqual(3);
  });

  test('CASE 2', () => {
    const s = [32, 22, 0, 31, 2, 19, 3];

    expect(max(toList(s))).toEqual(32);
  });

  test('CASE 3', () => {
    const s = [1400, 1401];

    expect(max(toList(s))).toEqual(1401);
  });
});
