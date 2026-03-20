# Evaluation

1. [Information](#information)
2. [Theorical questions](#theorical-questions)
3. [Debugging](#debugging)
4. [Xml Parsing](#xml-parser)
5. [Trees](#trees)

## Information

### Rating

- In the case of no coding exercises, the rating will depend of the answer you will make
- In the case of coding exercises, the rating will be composed of:
 * The execution of the program answers the expectations
 * Have edge cases been into account?
 * ...
- The entire code you will submit, will be kept in the exact same case **unless it is explicitly told**. In that case, some files might be replaced to run some tests. The global rating of the exercise will depend of the number of success tests, so **take time to test your code and think about what can go wrong**.
- The way you have coded, the code quality, lisibility, leaks... are also part of the global rating of the exercises.

**Keep in mind that a code that does not compile cannot be run. In that case lots of points will be lost**

### Submit quality

- The way you will deliver your submission is also evaluated (even if it is not the main part of the rating).
- You must submit a `FIRSTNAME_LASTNAME.zip` file in the [drive](https://drive.google.com/drive/folders/1G_J7wIqgDNXLhvD_5eTI5l38WtFnAsii?usp=sharing)
- Late submission will be penalized
- Every unecessary files must be removed from your archive
 * `git` files
 * temporary files such compilation files for instance
 * IDE files 
- Your final project's weight must be close to the initial project (because you will only submit text files).

## Exercises

### Theorical questions
*Folder* : **Questions**\
*Estimated maximal time* : 10 minutes

You will find in this folder a markdown file which contains several questions. You must answer those questions directly in the file.

- Don't bother you with markdown notation, text format is sufficient
- Don't write tons of lines for each questions. Short and precise answer will be appreciate.

### Debugging
*Folder* : **DirtySpaceInvaders**\
*Estimated maximal time* : 90 minutes

In this folder, you will find a broken and bugy solution that you have to fix.

Just in case you have no idea what a `Space Invader` is, here are some references :
- [Video](https://www.youtube.com/watch?v=8Rbi8cfDvVY).
- [Online video game](https://freeinvaders.org/)

Here some infornation about the 

In the `CleanSpaceInvaders` folder, you will find two executables which show you what the program looks like once it has been fixed. One of them uses a seed so you can reproduce the same behavior on our side using
```c++
	// Change the seed by the one you want to try
	rGen.seed(1);
```

You are free to fix the program in the way you want (the clearer the better) but you have to keep a track of what you are doing, what is wrong, why... in the `recap.txt` file.

### Islands
*Folder* : **Islands**\
*Estimated maximal time* : 20 minutes

The purpose of this exercise is to parse a `sounds.xml` file and store its content in a map to retrieve the data using the sound key. You will find more information directly in the code as comments.

**The `main` function is the only one that must not contain any code because it will be replaced. All code in that function will be lost. However, you can use it as a sandbox, you are free to use the way you want while developing.**

In this exercise, you have to implement, at least, those two functions:
- XmlCache::Parse
- XmlCache::GetSound

You are free to implement it the way you want:
- You can follow the guidelines in comments (if you pick that solution, you will need to only modify the `XmlCache.cpp` file) which help you implementing.
- Ignore the last statement and implement it the way you want. You only need to implement the function mentionned above.

