from abc import abstractmethod


class Operation:

    @abstractmethod
    def operate(self, text: str) -> str:
        pass


class ToUpper(Operation):

    def operate(self, text: str) -> str:
        return text.upper()


class CutHalf(Operation):

    def operate(self, text: str) -> str:
        return text[:int(len(text)/2)]


class DelWhitespace(Operation):

    def operate(self, text: str) -> str:
        return text.replace(" ", "")


class TheChain:

    def __init__(self):
        self.operations = []

    def add_operation(self, operation: Operation):
        self.operations.append(operation)

    def do_operations(self, text: str) -> str:
        for operation in self.operations:
            text = operation.operate(text)
        return text


if __name__ == '__main__':
    chain = TheChain()

    chain.add_operation(CutHalf())
    chain.add_operation(CutHalf())
    chain.add_operation(DelWhitespace())
    chain.add_operation(ToUpper())

    print(chain.do_operations("Super duper extra string, boom boom bing bing"))  # output: SUPERDUPER
