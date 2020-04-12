NULL = 0;

esc(str, i) {
    auto n;
    n = 0;
    while (i-- && str[i] == "**") n++;
    return (n % 2);
}

main() {
    auto i, j, k, l, c;
    i = j = k = l = 0;
    tk = getvec(2047); // 1024 tokens
    names = getvec(255); // 32 names
    while (src[i]) {
        switch (src[i]) {
            case "0" :: "9":
            case "a" :: "z":
            case "A" :: "Z":
            case "_":
            case ".":
                if (k < 8) names[l + k++] = src[i++];
                break;
            default:
                if (k) {
                    k = 0;
                         if (equal(names[l], "auto"))    { tk[j++] = "A"; tk[j++] = "U"; }
                    else if (equal(names[l], "break"))   { tk[j++] = "B"; tk[j++] = "R"; }
                    else if (equal(names[l], "case"))    { tk[j++] = "C"; tk[j++] = "S"; }
                    else if (equal(names[l], "default")) { tk[j++] = "D"; tk[j++] = "F"; }
                    else if (equal(names[l], "do"))      { tk[j++] = "D"; tk[j++] = "O"; }
                    else if (equal(names[l], "else"))    { tk[j++] = "L"; tk[j++] = "S"; }
                    else if (equal(names[l], "extrn"))   { tk[j++] = "X"; tk[j++] = "T"; }
                    else if (equal(names[l], "for"))     { tk[j++] = "F"; tk[j++] = "R"; }
                    else if (equal(names[l], "goto"))    { tk[j++] = "G"; tk[j++] = "T"; }
                    else if (equal(names[l], "if"))      { tk[j++] = "I"; tk[j++] = "F"; }
                    else if (equal(names[l], "next"))    { tk[j++] = "N"; tk[j++] = "X"; }
                    else if (equal(names[l], "repeat"))  { tk[j++] = "R"; tk[j++] = "P"; }
                    else if (equal(names[l], "return"))  { tk[j++] = "R"; tk[j++] = "T"; }
                    else if (equal(names[l], "switch"))  { tk[j++] = "S"; tk[j++] = "W"; }
                    else if (equal(names[l], "while"))   { tk[j++] = "W"; tk[j++] = "L"; }
                    else l++;
                }
                switch (src[i]) {
                    case ";":
                    case "*n":
                        tk[j++] = ";";
                        tk[j++] = NULL;
                    case NULL:
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
                    default:
                        break;
                }
        }
        while (src[++i] && src[i] <= " ");
    }
}
