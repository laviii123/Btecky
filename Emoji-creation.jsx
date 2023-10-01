import React, { useState } from 'react';
import './Emoji.css';

const Emoji = ({ emoji, animation }) => {
  const [animate, setAnimate] = useState(false);

  const handleClick = () => {
    setAnimate(true);
    setTimeout(() => {
      setAnimate(false);
    }, 1000);
  };

  return (
    <div className={`emoji ${animation}${animate ? ' animate' : ''}`} onClick={handleClick}>
      {emoji}
    </div>
  );
};

export default Emoji;
