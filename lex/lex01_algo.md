Certainly! Here’s an algorithm corresponding to the modified C code for the lexical analyzer:

### Algorithm for Lexical Analyzer

1. **Initialize Variables**
   - Set `line_number` to 1.
   - Set `token_number` to 0.
   - Initialize an empty character array `str` to store tokens.

2. **Open Input File**
   - Open the file `input.txt` for reading.

3. **Check File Opening**
   - If the file does not open successfully, print an error message and exit the program.

4. **Print Header**
   - Print the column headers: "Line no.", "Token no.", "Token", and "Lexeme".

5. **Read Characters from File**
   - While not at the end of the file:
     - Read a character `ch` from the file.
     - Initialize `i` to 0 and `flag` to 0.

6. **Character Classification**
   - **Operators**: If `ch` is one of `+`, `-`, `*`, or `/`:
     - Print the line number, token number, token type ("Operator"), and the character `ch`.
     - Increment the token number.
   - **Special Symbols**: If `ch` is one of `;`, `{`, `}`, `(`, `)`, `?`, `@`, `!`, `%`:
     - Print the line number, token number, token type ("Special symbol"), and the character `ch`.
     - Increment the token number.
   - **Digits**: If `ch` is a digit:
     - Print the line number, token number, token type ("Digit"), and the character `ch`.
     - Increment the token number.
   - **Identifiers/Keywords**: If `ch` is an alphabetic character:
     - Add `ch` to `str`.
     - Continue reading characters into `str` while they are alphanumeric and not a space.
     - Null-terminate the string in `str`.
     - Check if `str` matches any keyword in the predefined list:
       - If a match is found, set `flag` to 1.
     - If `flag` is 1:
       - Print the line number, token number, token type ("Keyword"), and the string `str`.
     - If `flag` is 0:
       - Print the line number, token number, token type ("Identifier"), and the string `str`.
     - Increment the token number.
   - **New Line**: If `ch` is a newline character (`\n`):
     - Increment the line number.

7. **Close Input File**
   - Close the `input.txt` file.

8. **End Program**
   - Exit the program.

### Summary
This algorithm outlines the steps the lexical analyzer takes to read and classify tokens from the input file, printing the results directly to the terminal. It includes initializing variables, reading characters, classifying them, and handling different types of tokens such as operators, special symbols, digits, keywords, and identifiers.
