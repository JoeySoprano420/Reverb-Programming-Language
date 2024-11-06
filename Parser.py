# Parser prototype in Python for Reverb

class Parser:
    def __init__(self, tokens):
        self.tokens = tokens
        self.current_token = None
        self.advance()

    def advance(self):
        self.current_token = self.tokens.pop(0) if self.tokens else None

    def parse(self):
        statements = []
        while self.current_token:
            if self.current_token[0] == 'PULSE':
                statements.append(self.parse_pulse())
            elif self.current_token[0] == 'STRIKE':
                statements.append(self.parse_strike())
            elif self.current_token[0] == 'DEDUCT':
                statements.append(self.parse_deduct())
            self.advance()
        return statements

    def parse_pulse(self):
        # Parsing a pulse stabilizer block
        self.advance()  # Move to the next token
        return {'type': 'PULSE', 'action': 'stabilize'}

    def parse_strike(self):
        # Parsing a proactive strike block
        self.advance()
        return {'type': 'STRIKE', 'action': 'preempt'}

    def parse_deduct(self):
        # Parsing a deductive reasoning block
        self.advance()
        return {'type': 'DEDUCT', 'action': 'analyze'}
