NULL = 0;

esc(str, i) {
    auto n;
    n = 0;
    while (i-- && str[i] == "**") n++;
    return (n % 2);
}

main() {
    auto i, j, k, c, raw[7];
    i = j = k = 0;
    tk = getvec(1023);
    while (src[i]) {
        while (src[i] && isSpace(src[i])) {
            k = 0;
            i++;
        }
        switch (src[i]) {
            case NULL:
                break;
            case "0" :: "9":
            case "a" :: "z":
            case "A" :: "Z":
            case "_":
            case ".":
                if (k < 8) raw[k++] = src[i++];
                break;
            case "(":
            case "[":
            case "{":
                tokens[j++] = "L";
                if (src[i] == "(") tk[j++] = 0;
                if (src[i] == "[") tk[j++] = 1;
                if (src[i] == "{") tk[j++] = 2;
                break;
            case ")":
            case "]":
            case "}":
                tokens[j++] = "R";
                if (src[i] == ")") tk[j++] = 0;
                if (src[i] == "]") tk[j++] = 1;
                if (src[i] == "}") tk[j++] = 2;
                break;
            case "'":
            case '"':
            case "`":
                c = src[i];
                i++;
                while (src[i] && (src[i] != c || esc(src, i))) {
                    i++;
                }
                break;
            case "=":
            case "<":
            case ">":
                break;
            case "|":
            case "&":
            case "+":
            case "-":
                break;
            case "**":
            case "/":
            case "!":
            case "~":
            case "^":
            case "%":
                break;
            case "#":
                break;
            default:
                break;
        }
        i++;
    }
}
