package com.amg.rubik;

import com.amg.rubik.cube.RubiksCube;
import com.amg.rubik.cube.Square;
import com.amg.rubik.graphics.CubeRenderer;
import com.badlogic.gdx.Application;
import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.InputMultiplexer;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.PerspectiveCamera;
import com.badlogic.gdx.graphics.g3d.Environment;
import com.badlogic.gdx.graphics.g3d.ModelBatch;
import com.badlogic.gdx.graphics.g3d.attributes.ColorAttribute;
import com.badlogic.gdx.graphics.g3d.environment.DirectionalLight;
import com.badlogic.gdx.graphics.g3d.utils.CameraInputController;

public class CubeApp extends ApplicationAdapter {

    private static final String tag = "rubik-app";

    RubiksCube cube;
    ModelBatch batch;
    PerspectiveCamera camera;
    Environment env;
    CameraInputController cameraController;

    @Override
    public void create () {
        Gdx.app.setLogLevel(Application.LOG_DEBUG);

        batch = new ModelBatch();

        env = new Environment();
        env.set(new ColorAttribute(ColorAttribute.AmbientLight, 0.4f, 0.4f, 0.4f, 1));
        env.add(new DirectionalLight().set(0.8f, 0.8f, 0.8f, -1, -0.8f, -0.2f));

        camera = new PerspectiveCamera(67, Gdx.graphics.getWidth(), Gdx.graphics.getHeight());
        camera.position.set(10, 10, 10);
        camera.lookAt(0, 0, 0);
        camera.near = 1;
        camera.far = 300;
        camera.update();
        cameraController = new CameraInputController(camera);
        cube = new RubiksCube(3);
        cube.setSpeed(1);
        cube.setRenderer(new Renderer());
        Gdx.input.setInputProcessor(
                new InputMultiplexer(new InputHandler(cube, camera), cameraController));
    }

    @Override
    public void render () {
        Gdx.gl.glViewport(0, 0, Gdx.graphics.getWidth(), Gdx.graphics.getHeight());
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT | GL20.GL_DEPTH_BUFFER_BIT);
        cameraController.update();
        batch.begin(camera);
        cube.draw();
        batch.end();

        cube.onNextFrame();
    }

    @Override
    public void dispose () {
        batch.dispose();
    }

    class Renderer implements CubeRenderer {

        @Override
        public void drawSquare(Square square) {
            drawSquare(square, 0, 0, 0, 0);
        }

        @Override
        public void drawSquare(Square square, float angle, float x, float y, float z) {
            square.getModelInstance().transform.setToRotation(x, y, z, angle);
            batch.render(square.getModelInstance(), env);
        }
    }
}
