const { reverseString } = require('./StringReversal.bs');

describe("String Reversal", () => {

    test("Case A", () => {
        const s = "hello";

        expect(reverseString(s)).toEqual("olleh");
    });

    test("Case B", () => {
        const s = "nicholas";

        expect(reverseString(s)).toEqual("salohcin");
    });

    test("Case C", () => {
        const s = "123";

        expect(reverseString(s)).toEqual("321");
    });
});




