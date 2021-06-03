class CodeExpression:

    def interpret(self, expression: str) -> str:
        pass


class InStatement(CodeExpression):

    def __init__(self, object: str):
        self.object = object

    def interpret(self, expression: str) -> str:
        if self.object in expression:
            return expression
        return ""


class IfStatement(CodeExpression):

    def __init__(self, object_: str, is_: str):
        self.object_ = object_
        self.is_ = is_

    def interpret(self, expression: str) -> str:
        if f"{self.object_} is {self.is_}" in expression:
            return expression
        return ""


if __name__ == '__main__':
    sentence = 'ann is a girl, but tom is a boy'

    in_stat = InStatement('tom')
    in_stat2 = InStatement('josh')

    if_sent = IfStatement('ann', 'a girl')
    if_sent2 = IfStatement('tom', 'a girl')

    # if "ann" is "a girl" and "tom" in sentence -> will print sentence if both true, '' if false
    print(if_sent.interpret(in_stat.interpret(sentence)))     # ann is a girl and tom in sentence
    print(if_sent.interpret(in_stat2.interpret(sentence)))    # ann is a girl and josh in sentence
    print(if_sent2.interpret(in_stat.interpret(sentence)))    # tom is a girl and tom in sentence
    print(if_sent2.interpret(in_stat2.interpret(sentence)), end='\n\n')   # tom is a girl and josh in sentence
    print('the same with bool:')
    print(bool(if_sent.interpret(in_stat.interpret(sentence))))     # ann is a girl and tom in sentence
    print(bool(if_sent.interpret(in_stat2.interpret(sentence))))    # ann is a girl and josh in sentence
    print(bool(if_sent2.interpret(in_stat.interpret(sentence))))    # tom is a girl and tom in sentence
    print(bool(if_sent2.interpret(in_stat2.interpret(sentence))))   # tom is a girl and josh in sentence
