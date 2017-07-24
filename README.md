# ft_select
42 School Project 


This project is meant to make you code a small program using termcaps which will allow you to pick from a list of choices and return it to your shell.

• “ft_select” gets a series of arguments. The list of argu- ments is displayed in your terminal.

• The user can move through the list of arguments using arrows (the list is circular).

• One or more choices can be selected or un-selected with the the space key. With each selection, the cursor must automatically position itself on the next element.

• When the user validates the selection with the return key, the list of choices will be sent back to shell. The latter (i.e. list of choices sent back) will be separated by a space.


Examples of execution:

<img width="405" alt="screen shot 2017-07-23 at 4 51 30 pm" src="https://user-images.githubusercontent.com/25576444/28504183-361db414-6fc7-11e7-8903-a7fbf5b8c725.png">

• The list must be seen on a few columns if the size of the windows does not have enough lines to show them all in one column. If the user resizes the window while he/she is using it, the ensemble of his choices will reposition automatically and the selected choices will remain. The cursor of selection must be repositioned in a reasonable manner after a resizing.


<img width="238" alt="screen shot 2017-07-23 at 5 05 13 pm" src="https://user-images.githubusercontent.com/25576444/28504306-aa712164-6fc9-11e7-986d-de43d853c9eb.png">

• If the window is too small to show everything (not enough lines and/or columns), the program reacts reasonably as long as the dimensions of the window aren’t sufficient. Under no circumstances, can the program quit or crash. As soon as the window is large enough, the program must function properly again.

<img width="881" alt="screen shot 2017-07-23 at 5 05 42 pm" src="https://user-images.githubusercontent.com/25576444/28504295-620a5620-6fc9-11e7-9dbe-340f30e6c84d.png">

<img width="1106" alt="screen shot 2017-07-23 at 5 06 19 pm" src="https://user-images.githubusercontent.com/25576444/28504297-7bb3ffa4-6fc9-11e7-9127-810d15f45992.png">


• If the user presses esc key, the program mustn’t send anything to the shell and it has to exit properly.

• If the user presses either delete or backspace, the element the cursor is pointing to must be erased from the list. If there are no more elements in the list, the behavior must be exactly the same as if the user had pressed esc.

• Choice non selected: normal text.

• Selected choice: inverse video text.

• Cursor’s position: underlined text.

• Selected choice + cursor’s position: inverse video underlined text.

• Whichever way the program ends, the default configuration of your terminal will be restored. This is true even after it received a signal.

• User is able to interrupt the program with ctrl+z and restore it with fg without seeing any changes in its behavior.
