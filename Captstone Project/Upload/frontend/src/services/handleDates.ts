import { parseISO } from "date-fns/parseISO";

const dateRegexp = /\d{4}-\d{2}-\d{2}/;

const doesValueLookLikeADateString = (propValue: any) => (
    propValue && typeof propValue === "string" && dateRegexp.test(propValue)
);

const recursivelyHydrateDates = <T>(data: T, maxDepth = 5): T => {
    const objects: any = [[data]];

    for (let depth = 0; depth < maxDepth; depth += 1) {
        const objectsToIterateNext: any[] = [];
        objects[depth].forEach((obj: any) => {
            if (obj && typeof obj === "object") {
                Object.keys(obj).forEach((k) => {
                    const isValuePotentialDate = doesValueLookLikeADateString(obj[k]);

                    const attemptedParsedValue = parseISO(obj[k]);
                    if (
                        isValuePotentialDate &&
                        !Number.isNaN(attemptedParsedValue.getTime())
                    ) {
                        // eslint-disable-next-line no-param-reassign
                        obj[k] = attemptedParsedValue;
                    } else {
                        objectsToIterateNext.push(obj[k]);
                    }
                });
            }
        });
        objects[depth + 1] = objectsToIterateNext;
    }
    return data;
};

export { recursivelyHydrateDates };