//neuroevolution based rockets    

//date:: 16july,2023
//author:: gagan mishra
//code:: creates rockets that evolve with time as per the genetic evolution algrithm to reach the target

final int lifespan=500, population=1000;
final float maxforce=0.5, maxvel=4, mutationRate=0.003;
PVector target;
int age=0, genCount=0;
float stat=0.0;
boolean alldead=false;

Population pop;
ArrayList<Obstacle>  obstacles=new ArrayList<Obstacle>();
int ix, iy, minObstacleSize=2;//intial mouse positions for adding objects

void setup() {
  size(600, 600);
  background(0);

  target=new PVector(width/2, 10);
  pop=new Population(new PVector(width/2, height));

  //ui
  print("Drag the mouse to create the obstacles");
}

void draw() {
  background(0);
  pop.run();

  if (age >= lifespan || alldead) {
    stat = pop.evaluate(); //evaluation calculates the maximum fitness and creates the mating pool
    pop.selection(new PVector(width/2, height));//selection selects from mating pool..does crssover..does mutation..crates the new population
    age = 0;
    genCount++;
    alldead=false;
  }

  //generation stats
  textSize(18);
  noStroke();
  fill(255, 128, 0);
  text("Generation: " + genCount, 20, 20);
  text("Age: " + age, 20, 40);
  text("Avg Fit: "+stat, 20, 60);


  //target
  fill(255);
  ellipse(target.x, target.y, 20, 20);

  //obstacle shoow
  for (Obstacle obs : obstacles) {
    obs.display();
  }
}

void mousePressed() {
  ix=mouseX;
  iy=mouseY;
}

void mouseReleased() {
  if (min(mouseX-ix, mouseY-iy) > minObstacleSize) {//adding new obstacle
    obstacles.add(new Obstacle(ix+(mouseX-ix)/2, iy+(mouseY-iy)/2, mouseX-ix, mouseY-iy)); //some quick math

    //restarting population
    pop=new Population(new PVector(width/2, height));
    genCount=0;
    age=0;
    stat=0;
  }
}
