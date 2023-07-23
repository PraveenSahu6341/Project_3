# Text Editor C++ Project

This repository contains a C++ text editor project that enables users to perform various text editing operations on text files. The text editor is implemented in C++ and provides a simple command-line interface for user interaction. The project includes features such as file opening, inserting, updating, appending, displaying, deleting lines, searching for substrings, saving changes, and supporting undo and redo functionality.

**Features and Functionalities:**

1. **Main Menu**: The text editor displays a main menu with different options, allowing users to choose various text editing operations.

2. **File Operations**: Users can open text files, save changes to the current file, and save changes to a new file or with a different name.

3. **Insert, Update, and Append**: Users can insert new lines of text, update existing lines, and append substrings to lines at specific line numbers.

4. **Display**: The text editor can display the current contents of the text file on the console.

5. **Delete**: Users have the option to delete a single line, delete the last line, or delete all lines in the text file.

6. **Search**: The editor provides a search functionality that allows users to find specific substrings within the text file.

7. **Undo and Redo**: The text editor supports undo and redo operations for most editing actions. Users can undo their previous operations and redo them if needed.

**Data Structure:**

The text editor uses a custom implementation of a singly linked list to store the lines of the text file. Each node in the linked list represents a line of text. The custom stack implementation is used to maintain the history of changes, enabling undo and redo functionalities.

**Usage:**

1. Open the text editor and choose the desired operation from the main menu (options 1 to 12).
2. For certain operations, such as insert, update, and append, the editor may prompt for additional inputs, such as the line number and the new content.
3. The editor provides the option to undo and redo the last performed action, allowing users to revert changes or reapply them.

**Important Notes:**

- Ensure that the file path and name are provided correctly when opening or saving files.
- The editor uses a custom stack implementation for undo and redo functionalities, ensuring efficient history tracking.

**Contributing:**

Contributions to this project are welcome. If you encounter any bugs or have suggestions for improvement, please feel free to open an issue or submit a pull request.

**Acknowledgments:**

This text editor project is inspired by the need for a simple and lightweight text editing tool implemented in C++. The project builds upon fundamental data structures and algorithms to provide essential text editing functionalities.
