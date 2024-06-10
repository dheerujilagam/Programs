const nodemailer = require('nodemailer');

const transporter = nodemailer.createTransport({
    service: 'Gmail',
    auth: {
      user: 'dheerujilagam@gmail.com',
      pass: 'dcytemwpllvxdfwn'
    }
});

const mailOptions = {
    from: 'dheerujilagam@gmail.com',
    to: 'dheerujilagam143@gmail.com',
    subject: 'Test Email',
    text: 'This is a test email sent from Node.js using nodemailer.'
  };
  
transporter.sendMail(mailOptions, (error, info) => {
    if (error) {
        console.error('Error sending email:', error);
    } else {
        console.log('Email sent:', info.response);
    }
});
