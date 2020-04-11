NULL = 0;

isSpace(c) return (c <= " ");
isDigit(c) return (c >= "0" && c <= "9");
isAlpha(c) return (c >= "a" && c <= "z" || c >= "A" && c <= "Z");
isValid(c) return (c >= "a" && c <= "z" || c >= "A" && c <= "Z" || c >= "0" && c <= "9" || c == "_" || c == ".");

leadEsc(str, i) {
    auto n;
    n = 0;
    while (i-- && str[i] == "**") n++;
    return n;
}

main() {
    auto i, j, x;
    i = j = x = 0;
    tk = getvec(1023);
    while (src[i]) {
        while (src[i] && isSpace(src[i])) i++;
        switch (src[i]) {
            case NULL:
                break;
            case "0" :: "9":
            case "a" :: "z":
            case "A" :: "Z":
            case "_":
            case ".":
                break;
            case "'":
            case '"':
            case "`":
                x = src[i];
                i++;
                while (src[i] && (src[i] != x || leadEsc(src, i) % 2)) {
                    i++;
                }
                break;
            case "=":
            case "<":
            case ">":
            case "!":
            case "~":
            case "^":
            case "|":
            case "&":
            case "+":
            case "-":
            case "**":
            case "/":
            case "%":
            case "#":
                break;
            default:
                break;
        }
    }
}
