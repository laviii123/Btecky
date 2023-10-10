import { useState } from "react";

import "./style.scss";
import data from "./data.json";

function App() {
  const [state, setState] = useState("System");
  const [navState, setNavState] = useState("");

  return (
    <>
      <nav className={navState}>
        <div className="nav_top">
          <div
            className="account"
            onClick={() => {
              setState("Accounts");
              setNavState("");
            }}
          >
            <img
              src="./img/nav/defAccount.webp"
              alt=""
              height="60"
              width="60"
            />
            <div>
              <p>Naman</p>
              <p>Local Account</p>
            </div>
          </div>
          <input
            type="text"
            className="search"
            placeholder="Find a setting "
            name="search"
          />
        </div>
        <div className="nav_bottom">
          {Object.keys(data).map((e) => {
            return (
              <div
                key={e}
                className={`navLink ${e === state ? "active" : ""}`}
                onClick={() => {
                  setState(e);
                  setNavState("");
                }}
              >
                <img
                  src={`./img/nav/${e}.webp`}
                  alt=""
                  height="16"
                  width="16"
                />
                {e}
              </div>
            );
          })}
          <div className="marker"></div>
        </div>
      </nav>

      {Object.keys(data).map((e) => {
        return (
          state === e && (
            <main key={e}>
              <h1>{e}</h1>
              <div className="tilesCont">
                {data[e].map((e) => {
                  switch (e.type) {
                    case "sysTop":
                      return (
                        <div className={e.type}>
                          <div className="left">
                            <img
                              src="./img/wall.webp"
                              className="device_img"
                              alt=""
                              height="72"
                              width="110.5"
                            />
                            <div className="column_device">
                              <p className="device_name">Welcome</p>
                              <p className="device_model">L417</p>
                              <p className="device_rename">Rename</p>
                            </div>
                          </div>
                          <div className="right">
                            <div className="column">
                              <img
                                src="./img/msft.svg"
                                alt=""
                                height="20"
                                width="20"
                              />
                              <p>
                                Microsoft 365
                                <br />
                                <span className="column_lower">
                                  View benefits
                                </span>
                              </p>
                            </div>
                            <div
                              className="column"
                              onClick={() => setState("Windows Update")}
                            >
                              <img
                                src="./img/nav/Windows Update.webp"
                                alt=""
                                height="20"
                                width="20"
                              />
                              <p>
                                Windows Update
                                <br />
                                <span className="column_lower">
                                  Last checked: {Math.ceil(Math.random() * 12)}{" "}
                                  hours ago
                                </span>
                              </p>
                            </div>
                          </div>
                        </div>
                      );
                    case "subHeading":
                    case "spacer":
                      return <div className={e.type}>{e.name}</div>;
                    case "tile":
                    case "tile square":
                    case "tile thin-blue":
                      return (
                        <div key={e.name} className={e.type}>
                          <span>{e.icon}</span>
                          <div>
                            <p>{e.name}</p>
                            <p className="tile_desc">{e.desc}</p>
                          </div>
                        </div>
                      );
                    default:
                      return console.log(`error - type ${e.type} not found`);
                  }
                })}
              </div>
            </main>
          )
        );
      })}

      <div
        className="navMenuBtn"
        onClick={() => setNavState(navState ? "" : "open")}
      >
        <svg fill="currentColor" viewBox="0 0 48 48" width={24} height={24}>
          <path d="M5.5 9a1.5 1.5 0 1 0 0 3h37a1.5 1.5 0 1 0 0-3h-37zm0 13.5a1.5 1.5 0 1 0 0 3h37a1.5 1.5 0 1 0 0-3h-37zm0 13.5a1.5 1.5 0 1 0 0 3h37a1.5 1.5 0 1 0 0-3h-37z" />
        </svg>
      </div>
    </>
  );
}
export default App;
