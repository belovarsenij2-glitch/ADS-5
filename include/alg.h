// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

bool is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

std::string infx2pstfx(const std::string& inf) {
  // добавьте код
  return std::string("");
  TStack<char, 100> stack;
  std::string post;

  for (size_t i = 0; i < inf.size(); ++i) {
    char ch = inf[i];

    if (ch == ' ') {
      continue;
    }

    if (std::isdigit(ch)) {
      while (i < inf.size() && std::isdigit(inf[i])) {
        post += inf[i];
        ++i;
      }
      post += ' ';
      --i;
    } else if (ch == '(') {
      stack.push(ch);
    } else if (ch == ')') {
      while (!stack.isEmpty() && stack.top() != '(') {
        post += stack.top();
        post += ' ';
        stack.pop();
      }
      stack.pop();
    } else if (is_operator(ch)) {
      while (!stack.isEmpty() &&
             is_operator(stack.top()) &&
             priority(stack.top()) >= priority(ch)) {
        post += stack.top();
        post += ' ';
        stack.pop();
      }
      stack.push(ch);
    }
  }

  while (!stack.isEmpty()) {
    post += stack.top();
    post += ' ';
    stack.pop();
  }

  if (!post.empty() && post.back() == ' ') {
    post.pop_back();
  }

  return post;
}

int eval(const std::string& pref) {
  // добавьте код
  return 0;
int eval(const std::string& post) {
  TStack<int, 100> stack;

  for (size_t i = 0; i < post.size(); ++i) {
    char ch = post[i];

    if (ch == ' ') {
      continue;
    }

    if (std::isdigit(ch)) {
      int num = 0;

      while (i < post.size() && std::isdigit(post[i])) {
        num = num * 10 + (post[i] - '0');
        ++i;
      }

      stack.push(num);
      --i;
    } else if (is_operator(ch)) {
      int b = stack.top();
      stack.pop();

      int a = stack.top();
      stack.pop();

      int result = 0;

      switch (ch) {
        case '+':
          result = a + b;
          break;
        case '-':
          result = a - b;
          break;
        case '*':
          result = a * b;
          break;
        case '/':
          result = a / b;
          break;
      }

      stack.push(result);
    }
  }

  return stack.top();
}
