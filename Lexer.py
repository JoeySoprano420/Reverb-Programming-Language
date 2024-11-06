# Lexer prototype in Python for Reverb

import re

class Lexer:
    def __init__(self, code):
        self.code = code
        self.tokens = []
        self.current_pos = 0

    def tokenize(self):
        # Token patterns for Reverb's unique syntax, including meta-indents and pulse control
        token_specification = [
            ('PULSE', r'\bpulse\b'),  # Pulse stabilizer keyword
            ('STRIKE', r'\bstrike\b'),  # Proactive strike keyword
            ('AUTO_GAUGE', r'\bauto_gauge\b'),  # Auto-gauging mechanism
            ('DEDUCT', r'\bdeduct\b'),  # Deductive reasoning
            ('NUMBER', r'\d+'),  # Integer numbers
            ('ID', r'[A-Za-z_]\w*'),  # Identifiers
            ('NEWLINE', r'\n'),  # New lines
            ('SKIP', r'[ \t]+'),  # Skip spaces and tabs
            ('MISMATCH', r'.'),  # Any other character
        ]
        token_regex = '|'.join('(?P<%s>%s)' % pair for pair in token_specification)
        
        for mo in re.finditer(token_regex, self.code):
            kind = mo.lastgroup
            value = mo.group()
            if kind == 'NEWLINE':
                self.current_pos += 1
            elif kind != 'SKIP':
                self.tokens.append((kind, value))
        return self.tokens
