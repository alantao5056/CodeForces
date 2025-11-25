import ast

class Checker(ast.NodeVisitor):
    def __init__(self):
        self.x = False
        self.n = False
        self.while_loop = False

    def visit_Assign(self, node):
        for target in node.targets:
            if isinstance(target, ast.Name):
                if target.id == "x":
                    self.x = True
                elif target.id == "n":
                    self.n = True

    def visit_While(self, node):
        self.while_loop = True
        self.generic_visit(node)
