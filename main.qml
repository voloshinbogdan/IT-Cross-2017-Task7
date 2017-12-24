import QtQuick 2.4


Canvas
{

	width: 640
	height: 480
	function rnd(a, b)
	{
		return a + (b - a) * Math.random()
	}


	onPaint:
	{
		var ctx = getContext("2d")
		ctx.fillStyle = 'rgb(0.1, 0.1, 0.1)'
		ctx.fillRect(0, 0, width, height)
		for (var i = 0; i < stars.length; i ++)
		{
			var star = JSON.parse(stars[i])[0]
			
			var c = Qt.rgba(star.r, star.g, star.b, 1.)
			ctx.fillStyle = c
			ctx.beginPath()
			ctx.ellipse(star.x, star.y, star.size, star.size)
			ctx.text(star.name, star.x, star.y);
			ctx.fill()
		}
	} // onPaint
} // Canvas
