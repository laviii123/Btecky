import { useState,useEffect } from 'react'
import './App.css';
import searchIcon from './assets/search.svg';
import MovieCard from './MovieCard';

const url = 'http://www.omdbapi.com?apikey=a8326009'

const App = () => {
  const [title, setTitle] = useState('');
  const [movies, setMovies] = useState([]);
  useEffect(() => {
    search(title);
  }, []);

  const search = async (title) => {
      const response = await fetch(`${url}&s=${title}`);
      const data = await response.json();
      console.log(data);
      setMovies(data.Search);
    }
  return (
    <div className='app'>
      <h1>MovieLand</h1>
      <div className='search'>
        <input type='text' placeholder='Search for movies...' value={title} onChange={(e) => setTitle(e.target.value)} />
        <img src={searchIcon} alt='search' onClick={() => search(title)} />
      </div>
      {
        movies?.length > 0
          ? (
            <div className='container'>
              {movies.map((movie) => (
            <MovieCard movie={movie} />
              ))}
            </div>
          ) : (
            <div className='empty'>
              <h2>Movie Not Found</h2>
            </div>
        )
      }
      
    </div>
  )
}

export default App