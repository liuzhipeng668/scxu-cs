/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "util.h"

#include "globals.h"

/* Procedure printToken prints a token
 * and its lexeme to the listing file
 */
void printToken(TokenType token, const char *tokenString) {
  switch (token) {
    case IF:
    case THEN:
    case END:
    case REPEAT:
    case UNTIL:
    case READ:
    case WRITE:
    case FOR:
    case DO:
    case ENDDO:
      fprintf(listing, "reserved word: %s\n", tokenString);
      break;
    case ELSE:
      fprintf(listing, "else\n");
      break;
    case TO:
      fprintf(listing, "to\n");
      break;
    case DOWNTO:
      fprintf(listing, "downto\n");
      break;
    case ASSIGN:
      fprintf(listing, ":=\n");
      break;
    case LT:
      fprintf(listing, "<\n");
      break;
    case EQ:
      fprintf(listing, "=\n");
      break;
    case GT:
      fprintf(listing, ">\n");
      break;
    case LE:
      fprintf(listing, "<=\n");
      break;
    case GE:
      fprintf(listing, ">=\n");
      break;
    case NE:
      fprintf(listing, "<>\n");
      break;
    case LPAREN:
      fprintf(listing, "(\n");
      break;
    case RPAREN:
      fprintf(listing, ")\n");
      break;
    case SEMI:
      fprintf(listing, ";\n");
      break;
    case PLUS:
      fprintf(listing, "+\n");
      break;
    case MINUS:
      fprintf(listing, "-\n");
      break;
    case TIMES:
      fprintf(listing, "*\n");
      break;
    case OVER:
      fprintf(listing, "/\n");
      break;
    case MOD:
      fprintf(listing, "%%\n");
      break;
    case POW:
      fprintf(listing, "^\n");
      break;
    case REOR:
      fprintf(listing, "|\n");
      break;
    case RECON:
      fprintf(listing, "&\n");
      break;
    case RECLOSURE:
      fprintf(listing, "#\n");
      break;
    case REOPTION:
      fprintf(listing, "?\n");
      break;
    case BITAND:
      fprintf(listing, "and\n");
      break;
    case BITOR:
      fprintf(listing, "or\n");
      break;
    case BITNOT:
      fprintf(listing, "not\n");
      break;
    case ENDFILE:
      fprintf(listing, "EOF\n");
      break;
    case NUM:
      fprintf(listing, "NUM, val= %s\n", tokenString);
      break;
    case ID:
      fprintf(listing, "ID, name= %s\n", tokenString);
      break;
    case ERROR:
      fprintf(listing, "ERROR: %s\n", tokenString);
      break;
    default: /* should never happen */
      fprintf(listing, "Unknown token: %d\n", token);
  }
}

std::string strToken(TokenType token, const char *tokenString) {
  std::string res;

  switch (token) {
    case IF:
    case THEN:
    case END:
    case REPEAT:
    case UNTIL:
    case READ:
    case WRITE:
    case FOR:
    case DO:
    case ENDDO:
      // fprintf(listing, "reserved word: %s\n", tokenString);
      res += "reserved word: " + std::string(tokenString) + "\n";
      break;
    case ELSE:
      // fprintf(listing, "else\n");
      res += "else\n";
      break;
    case TO:
      // fprintf(listing, "to\n");
      res += "to\n";
      break;
    case DOWNTO:
      // fprintf(listing, "downto\n");
      res += "downto\n";
      break;
    case ASSIGN:
      // fprintf(listing, ":=\n");
      res += ":=\n";
      break;
    case LT:
      // fprintf(listing, "<\n");
      res += "<\n";
      break;
    case EQ:
      // fprintf(listing, "=\n");
      res += "=\n";
      break;
    case GT:
      // fprintf(listing, ">\n");
      res += ">\n";
      break;
    case LE:
      // fprintf(listing, "<=\n");
      res += "<=\n";
      break;
    case GE:
      // fprintf(listing, ">=\n");
      res += ">=\n";
      break;
    case NE:
      // fprintf(listing, "<>\n");
      res += "<>\n";
      break;
    case LPAREN:
      // fprintf(listing, "(\n");
      res += "(\n";
      break;
    case RPAREN:
      // fprintf(listing, ")\n");
      res += ")\n";
      break;
    case SEMI:
      // fprintf(listing, ";\n");
      res += ";\n";
      break;
    case PLUS:
      // fprintf(listing, "+\n");
      res += "+\n";
      break;
    case MINUS:
      // fprintf(listing, "-\n");
      res += "-\n";
      break;
    case TIMES:
      // fprintf(listing, "*\n");
      res += "*\n";
      break;
    case OVER:
      // fprintf(listing, "/\n");
      res += "/\n";
      break;
    case MOD:
      // fprintf(listing, "%%\n");
      res += "%%\n";
      break;
    case POW:
      // fprintf(listing, "^\n");
      res += "^\n";
      break;
    case REOR:
      // fprintf(listing, "|\n");
      res += "|\n";
      break;
    case RECON:
      // fprintf(listing, "&\n");
      res += "&\n";
      break;
    case RECLOSURE:
      // fprintf(listing, "#\n");
      res += "#\n";
      break;
    case REOPTION:
      // fprintf(listing, "?\n");
      res += "?\n";
      break;
    case BITAND:
      // fprintf(listing, "and\n");
      res += "and\n";
      break;
    case BITOR:
      // fprintf(listing, "or\n");
      res += "or\n";
      break;
    case BITNOT:
      // fprintf(listing, "not\n");
      res += "not\n";
      break;
    case ENDFILE:
      // fprintf(listing, "EOF\n");
      res += "EOF\n";
      break;
    case NUM:
      // fprintf(listing, "NUM, val= %s\n", tokenString);
      res += "NUM, val: " + std::string(tokenString) + "\n";
      break;
    case ID:
      // fprintf(listing, "ID, name= %s\n", tokenString);
      res += "ID, name: " + std::string(tokenString) + "\n";
      break;
    case ERROR:
      // fprintf(listing, "ERROR: %s\n", tokenString);
      res += "ERROR: " + std::string(tokenString) + "\n";
      break;
    default: /* should never happen */
      // fprintf(listing, "Unknown token: %d\n", token);
      res += "Unknown token: " + std::to_string(token) + "\n";
  }

  return res;
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode *newStmtNode(StmtKind kind) {
  TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
  int i;
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else {
    for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
  }
  return t;
}

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode *newExpNode(ExpKind kind) {
  TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
  int i;
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else {
    for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char *copyString(char *s) {
  int n;
  char *t;
  if (s == NULL) return NULL;
  n = strlen(s) + 1;
  t = (char *)malloc(n);
  if (t == NULL)
    fprintf(listing, "Out of memory error at line %d\n", lineno);
  else
    strcpy(t, s);
  return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno += 2
#define UNINDENT indentno -= 2

/* printSpaces indents by printing spaces */
static void printSpaces(void) {
  int i;
  for (i = 0; i < indentno; i++) fprintf(listing, " ");
}

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode *tree) {
  int i;
  INDENT;
  while (tree != NULL) {
    printSpaces();
    if (tree->nodekind == StmtK) {
      switch (tree->kind.stmt) {
        case IfK:
          fprintf(listing, "If\n");
          break;
        case RepeatK:
          fprintf(listing, "Repeat\n");
          break;
        case AssignK:
          fprintf(listing, "Assign to: %s\n", tree->attr.name);
          break;
        case ReadK:
          fprintf(listing, "Read: %s\n", tree->attr.name);
          break;
        case WriteK:
          fprintf(listing, "Write\n");
          break;
        case ForK:
          fprintf(listing, "For\n");
          break;
        case PlusAssignK:
          fprintf(listing, "Plus Assign to: %s\n", tree->attr.name);
          break;
        default:
          fprintf(listing, "Unknown ExpNode kind\n");
          break;
      }
    } else if (tree->nodekind == ExpK) {
      switch (tree->kind.exp) {
        case OpK:
          fprintf(listing, "Op: ");
          printToken(tree->attr.op, "\0");
          break;
        case ConstK:
          fprintf(listing, "Const: %d\n", tree->attr.val);
          break;
        case IdK:
          fprintf(listing, "Id: %s\n", tree->attr.name);
          break;
        default:
          fprintf(listing, "Unknown ExpNode kind\n");
          break;
      }
    } else
      fprintf(listing, "Unknown node kind\n");
    for (i = 0; i < MAXCHILDREN; i++) {
      if (tree->child[i] != NULL) printTree(tree->child[i]);
    }
    tree = tree->sibling;
  }
  UNINDENT;
}

#define INDENT_BRANCH indentno += 1
#define UNINDEN_BRANCH indentno -= 1

/* printSpaces indents by printing dots */
static std::string strBranch(void) {
  std::string res;

  int i;
  for (i = 0; i < indentno; i++) {
    if (i < indentno - 1) {
      // fprintf(listing, "     ");
      res += "     ";
    } else {
      // fprintf(listing, "|___ ");
      res += "|___ ";
    }
  }

  return res;
}

std::string strSyntaxTree(TreeNode *tree) {
  std::string res;

  int i;
  INDENT_BRANCH;
  while (tree != NULL) {
    res += strBranch();
    if (tree->nodekind == StmtK) {
      switch (tree->kind.stmt) {
        case IfK:
          // fprintf(listing, "If\n");
          res += "If\n";
          break;
        case RepeatK:
          // fprintf(listing, "Repeat\n");
          res += "Repeat\n";
          break;
        case AssignK:
          // fprintf(listing, "Assign to: %s\n", tree->attr.name);
          res += "Assign to: " + std::string(tree->attr.name) + "\n";
          break;
        case ReadK:
          // fprintf(listing, "Read: %s\n", tree->attr.name);
          res += "Read: " + std::string(tree->attr.name) + "\n";
          break;
        case WriteK:
          // fprintf(listing, "Write\n");
          res += "Write\n";
          break;
        case ForK:
          // fprintf(listing, "For\n");
          res += "For\n";
          break;
        case PlusAssignK:
          // fprintf(listing, "Plus Assign to: %s\n", tree->attr.name);
          res += "Plus Assign to: " + std::string(tree->attr.name) + "\n";
          break;
        default:
          // fprintf(listing, "Unknown ExpNode kind\n");
          res += "Unknown ExpNode kind\n";
          break;
      }
    } else if (tree->nodekind == ExpK) {
      switch (tree->kind.exp) {
        case OpK:
          // fprintf(listing, "Op: ");
          res += "Op: ";
          res += strToken(tree->attr.op, "\0");
          break;
        case ConstK:
          // fprintf(listing, "Const: %d\n", tree->attr.val);
          res += "Const " + std::to_string(tree->attr.val) + "\n";
          break;
        case IdK:
          // fprintf(listing, "Id: %s\n", tree->attr.name);
          res += "Id: " + std::string(tree->attr.name) + "\n";
          break;
        default:
          // fprintf(listing, "Unknown ExpNode kind\n");
          res += "Unknown ExpNode kind\n";
          break;
      }
    } else {
      // fprintf(listing, "Unknown node kind\n");
      res += "Unknown node kind\n";
    }
    for (i = 0; i < MAXCHILDREN; i++) {
      if (tree->child[i] != NULL) res += strSyntaxTree(tree->child[i]);
    }
    tree = tree->sibling;
  }
  UNINDEN_BRANCH;

  return res;
}
