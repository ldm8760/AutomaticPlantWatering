import { useState } from 'react'
import Button from '@mui/material/Button';
import './App.css'

function App() {
    const [moistureLevel, setMoistureLevel] = useState(null);

    async function getMoisture() {
        let result = await fetch("http://localhost:8080/measure");
        let data = await result.json();
        setMoistureLevel(data);
    }

    async function waterPlant() {
        await fetch("http://localhost:8080/water");
    }

    return (
        <>
            <h1>Watering System Manager</h1>
            <Button
                onClick={() => {
                    getMoisture();
                }}
            >
                Update Moisture
            </Button>
            <Button
                onClick={() => {
                    waterPlant();
                }}
            >
                Water Plant
            </Button>
            <p>{moistureLevel}</p>
        </>
    )
}

export default App
