// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include <cctype>
#include "tstack.h"

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infx2pstfx(const std::string& inf) {
    std::string post = "";
    TStack<char, 100> stack;

    for (size_t i = 0; i < inf.length(); ++i) {
        char c = inf[i];

        if (c == ' ') continue;

        if (std::isdigit(c)) {
            while (i < inf.length() && std::isdigit(inf[i])) {
                post += inf[i];
                i++;
            }
            post += ' ';
            i--;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.get() !=Code'(') {
                post += stack.get();
                post += ' ';
                stack.pop();
            }
            if (!stack.isEmpty()) {
                stack.pop();
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack.isEmpty() &&
                   getPriority(stack.get()) >= getPriority(c)) {
                post += stack.get();
                post += ' ';
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        post += stack.get();
        post += ' ';
        stack.pop();
    }

    if (!post.empty() && post.back() == ' ') {
        post.pop_back();
    }

    return post;
}

int eval(const std::string& pref) {
    TStack<int, 100> stack;

    for (size_t i = 0; i < pref.length(); ++i) {
        char c = pref[i];

        if (c == ' ') continue;

        if (std::isdigit(c)) {
            int num = 0;
            while (i < pref.length() && std::isdigit(pref[i])) {
                num = num * 10 + (pref[i] - '0');
                i++;
            }
            stack.push(num);
            i--;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int op2 = stack.get(); stack.pop();
            int op1 = stack.get(); stack.pop();

            int res = 0;
            switch (c) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/':
                    if (op2 != 0) res = op1 / op2;
                    break;
            }
            stack.push(res);
        }
    }

    return stack.isEmpty() ? 0 : stack.get();
}
