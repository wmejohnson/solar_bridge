day 1:

after the first day of working on this here are some thoughts and TODO's

1. in the original there's a clusetering thing going on, see how things are kinga getting bunched up. things near each other are also attracted to each other
2. need to think about geometry:
    - see all that blue space around the borders? maybe i could create the vines and then draw a line around them, outlining the shape (the blue in the original)
    - maybe just make each vine class create it's own geometry, and then do something so that if an area is above a certain density threshold then vines aren't outlined
    - need to think about negative space. the black in the original creates a really nice image, right now mine is just a circle. could i use an image mask, or a shaping function, or just a combination of attractors
    - could i straigt up do cylinders?
3. post-processing
    - implement some sort of chromatic abberation
4. growing
    - maybe instead of moving towards an attractor they have a lifespan and the negative space in the center is defined by each vines speed and lifespan working together 
5. interactivity
    - make an int slider for the nVines so that each time i restart i can create a new amount of vines
    - midi support


day 2:

okay so there's a lot of ways to grow these things - vector fields, autonomous particles, much of which i'm already onto

*** i think what i car about more than the growth, is the actual drawing of the gooey, tenticle like, drop. it's so antitehetical to the aesthetic of generative computer graphics

