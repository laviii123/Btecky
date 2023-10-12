
class Rocket {
  PVector pos, vel, acc;
  DNA dna;
  boolean crashed=false, reached=false;
  float fitness=0.0;
  float ageWhenReachedorCrashed=0.0;

  Rocket(PVector pos_) {
    pos=pos_.copy();
    vel=new PVector(0, 0);
    acc=new PVector(0, -0.01);
    dna=new DNA();
    fitness=0.0;
    ageWhenReachedorCrashed=0.0;
    crashed=false;
    reached=false;
  }

  Rocket(PVector pos_, DNA dna_) {
    pos=pos_.copy();
    vel=new PVector(0, 0);
    acc=new PVector(0, -0.01);
    dna=dna_;
    fitness=0.0;
    ageWhenReachedorCrashed=0.0;
    crashed=false;
    reached=false;
  }

  void applyForce(PVector force) {
    acc.add(force);
  }

  void update() {
    if (drt()<10) {
      reached=true;
      ageWhenReachedorCrashed=age;
      pos=target.copy();
    } else if (pos.x<0 || pos.x>width || pos.y<0 || pos.y>height) {
      crashed=true;
      ageWhenReachedorCrashed=age;
    }


    if (!crashed && !reached) {
      applyForce(dna.genes[age]);

      vel.add(acc);
      pos.add(vel);
      acc.mult(0);
      vel.limit(maxvel);
    }
  }

  void display() {
    pushMatrix();

    if (reached) {
      fill(114, 232, 91);
    } else if (crashed) {
      fill(232, 91, 94);
    } else {
      fill(255, 100);
    }

    translate(pos.x, pos.y);
    rotate(vel.heading());
    noStroke();
    rectMode(CENTER);
    rect(0, 0, 25, 5);
    ellipse(12, 0, 10, 5);

    popMatrix();
  }

  void calcFitness() {
    fitness=map(drt(), 0, height, 1000, 0);//closer to rocket
    if(drt()<100)fitness*=10;//gicing boost to rcloser rockets
    
    if (reached) {
      fitness*=10;//fitness boost if reached
      float tmp=map(ageWhenReachedorCrashed, 0, lifespan, 1000, 0);
      fitness+=tmp;//the younger the more fitness
    }
    if (crashed) {
      fitness/=10;//fitness lost if not reached
    }
  }

  Rocket crossover(Rocket prt, PVector pos_) {
    DNA newDna=dna.crossingover(prt.dna);
    return (new Rocket(pos_, newDna));
  }

  float drt() {////distanceRocketTarget
    return dist(pos.x, pos.y, target.x, target.y);
  }
}
