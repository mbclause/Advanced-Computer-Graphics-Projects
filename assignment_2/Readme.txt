•Name of student:


Michael Clausen


*How do you compile and run your code?


Type make.
Usage - ./assignment_2 data/Modelx


•Did you collaborate with anyone in the class? If so, let us know who you talked to and what sort of help you gave or received.


Jacob Re


•Were there any references (books, papers, websites, etc.) that you found particularly helpful for completing your assignment? Please provide a list.


Our main resource was the professor, who helped us during office hours and by email. We also used ChatGPT for help debugging occasionally. 


•Are there any known problems with your code? If so, please provide a list and, if possible, describe what you think the cause is and how you might fix them if you had more time or motivation. This is very important, as we’re much more likely to assign partial credit if you help us understand what’s going on.




The main problem we encountered in this assignment was while implementing updateMesh, which is the core of the SSD. We thought that we had implemented this portion correctly, but when we made the solution and tried to move the sliders, it would immediately crash and give a segmentation fault. As we know, this is likely due to accessing memory that is out of bounds, probably when trying to translate down joints. However, we did not have enough time to solve the segmentation fault issue, and the professor mentioned that updateMesh tends to be tricky and prone to segmentation faults. We tried to debug this by changing some of the loop conditions to see if they were perhaps going out of bounds, and also by adding some checks to make sure no out of bounds memory was accessed. While these checks did prevent the segmentation faults, it resulted in strange shapes being drawn out of the mesh, and we couldn't imagine that the correct implementation would have to do checks such as that.






•Got any comments about this assignment that you’d like to share? Was it too long? Too hard? Were the requirements unclear? Did you have fun, or did you hate it? Did you learn something, or was it a total waste of your time? Feel free to be brutally honest; we promise we won’t take it personally.


This assignment was definitely easier. I’m starting to think in linear algebra which good.