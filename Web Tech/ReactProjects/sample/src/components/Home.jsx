import React, {useState} from 'react';
// import axios from 'axios'
import axios from "axios";
const Home = () => {
    const [formData, setFormData] = useState({});

    const handleChange = (e) => {
        setFormData({...formData, [e.target.name]:e.target.value});
    };

    const handleSubmit = (e) => {
        e.preventDefault();
        axios.post('http://localhost:8000', formData).then((res)=>{
            alert("Data submitted successfully");
        }).catch((error)=>{
            console.log(error)
        })
        console.log(formData);
    }

    return (
        <div className='container'>
            <h2>Contact Form</h2>
            <form>
                <label>
                    First Name : <t/>
                    <input
                        type='text'
                        name='firstName'
                        placeholder='Enter First Name'
                        onChange={handleChange}
                        required
                    />
                </label><br/><br/>
                <label>
                    Last Name : <t/>
                    <input
                        type='text'
                        name='lastName'
                        placeholder='Enter Last Name'
                        onChange={handleChange}
                        required
                    />
                </label><br/><br/>
                <label>
                    Email : <t/>
                    <input
                        type='email'
                        name='email'
                        placeholder='Enter Email'
                        onChange={handleChange}
                        required
                    />
                </label><br/><br/>
                <label>
                    Message : <t/>
                    <textarea
                        name='message'
                        placeholder='Enter Message'
                        onChange={handleChange}
                        required
                    />
                </label><br/><br/>
                <button type='submit' onClick={handleSubmit}>Submit</button>
            </form>
        </div>
    );
}

export default Home