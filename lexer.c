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
            case ")":
            case "]":
            case "}":
                tk[j++] = str[i];
                tk[j++] = NULL;
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
                tk[j++] = src[i];
                if (src[++i] == src[i] || src[i] == "=") {
                    tk[j++] = src[i];
                } else {
                    i--;
                    tk[j++] = NULL;
                }
                break;
            case "|":
            case "&":
            case "+":
            case "-":
                tk[j++] = src[i];
                i++;
                if (src[i] == src[i-1] || src[i] == "=") {
                    tk[j++] = src[i];
                } else {
                    i--;
                    tk[j++] = NULL;
                }
                break;
            case "**":
            case "/":
            case "!":
            case "~":
            case "^":
            case "%":
                tk[j++] = src[i];
                tk[j++] = NULL;
                break;
            case "#":
                tk[j++] = "#";
                switch (src[++i]) {
                    case "#":
                    case "+":
                    case "-":
                    case "**":
                    case "/":
                        tk[j++] = src[i];
                        break;
                    default:
                        tk[j++] = NULL;
                        i--;
                        break;
                }
                break;
            case ";":
                break;
            default:
                break;
        }
        i++;
    }
}
