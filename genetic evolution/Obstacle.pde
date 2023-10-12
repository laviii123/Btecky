
class Obstacle {
  int x, y, w, h;

  Obstacle(int x_, int y_, int w_, int h_) {
    x=x_;
    y=y_;
    w=w_;
    h=h_;
  }

  void checkCollision(Rocket r) {
    if (r.pos.x>(x-w/2) && r.pos.x<(x+w/2) && r.pos.y>(y-h/2) && r.pos.y<(y+h/2) ) {
      r.crashed=true;
      r.fitness/=20;//if it crashes with an obstacle decrease its fitness even further
      r.fitness*=map(r.ageWhenReachedorCrashed,0,lifespan,0,1);//if it crashes with obstacle early it gets punished
    }
  }

  void display() {
    fill(255);
    rect(x, y, w, h);

    fill(255, 0, 0);
    ellipse(x, y, 5, 5);
  }
}
