var grid = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

var sizeInput = document.getElementById("sizeslect");
var scorelabel = document.getElementById('score');

var score = 0;
var size = 4;
var width = grid.width / size - 5;

var cells = [];
var fontsize;
var loss = false;

startgame();


function startgame() {
  createcell();
  drawAllcell();
  pastenewcell();
}

function cell(row, col) {
  this.value = 0;
  this.x = col * width + 5 * (col + 1);
  this.y = row * width + 5 * (row + 1);
}

function createcell() {
  for (var i = 0; i < size; i++) {
    cells[i] = [];
    for (var j = 0; j < size; j++) {
      cells[i][j] = new cell(i, j);
    }
  }
}

function drawCell(cell) {
  ctx.beginPath();
  ctx.rect(cell.x, cell.y, width, width);

  switch (cell.value){
    case 0 : ctx.fillStyle = '#A9A9A9'; break;
    case 2 : ctx.fillStyle = '#efaf81'; break;
    case 4 : ctx.fillStyle = 'Khaki'; break;
    case 8 : ctx.fillStyle = 'Orange'; break;
    case 16 : ctx.fillStyle = 'DarkOrange'; break;
    case 32 : ctx.fillStyle = 'FireBrick'; break;
    case 64 : ctx.fillStyle = 'red'; break;
    case 128 : ctx.fillStyle = '#ddd577'; break;
    case 256 : ctx.fillStyle = '#e0d664'; break;
    case 512 : ctx.fillStyle = '#c6ba31'; break;
    case 1024 : ctx.fillStyle = '#d8c817'; break;
    case 2048 : ctx.fillStyle = '#f9e507'; break;
    case 4096 : ctx.fillStyle = 'Black'; break;
    default : ctx.fillStyle = '#efaf81';
  }
  ctx.fill();
  if (cell.value) {
    fontsize = width / 2;
    ctx.font = fontsize + "px Aerial";
    ctx.fillStyle = "White";
    ctx.textAlign = "center";
    ctx.fillText(cell.value, cell.x + width / 2, cell.y + width / 2);
  }

}

function drawAllcell() {
  for (var i = 0; i < size; i++) {
    for (var j = 0; j < size; j++) {
      drawCell(cells[i][j]);
    }
  }
}

function pastenewcell() {
  while (true) {
    var row = Math.floor(Math.random() * size);
    var col = Math.floor(Math.random() * size);
    if (!cells[row][col].value) {
      cells[row][col].value = 2 * Math.ceil(Math.random() * 2);
      drawAllcell();
      return;
    }
  }
}

document.onkeydown = function(event) {
  if (!loss) {
    if (event.key == 'ArrowUp') {
      moveUp();
    } else if (event.key == 'ArrowDown') {
      moveDown();
    } else if (event.key == 'ArrowLeft') {
      moveLeft();
    } else if (event.key == 'ArrowRight') {
      moveRight();
    }
  }
}


function moveUp() {
  var i, j, row;
  for (j = 0; j < size; j++) {
    for (i = 1; i < size; i++) {
      if (cells[i][j].value) {
        row = i;
        while (row > 0) {
          if (!cells[row - 1][j].value) {
            cells[row - 1][j].value = cells[row][j].value;
            cells[row][j].value = 0;
            row--;
          } else if (cells[row][j].value == cells[row - 1][j].value) {
            cells[row - 1][j].value *= 2;

            cells[row][j].value = 0;
            break;
          } else {
            break;
          }
        }
      }
    }
  }
  pastenewcell();
}

function moveDown() {
  var i, j, row;
  for (j = 0; j < size; j++) {
    for (i = size - 2; i >= 0; i--) {
      if (cells[i][j].value) {
        row = i;
        while (row + 1 < size) {
          if (!cells[row + 1][j].value) {
            cells[row + 1][j].value = cells[row][j].value;
            cells[row][j].value = 0;
            row++;
          } else if (cells[row + 1][j].value == cells[row][j].value) {
            cells[row + 1][j].value *= 2;

            cells[row][j].value = 0;
            break;
          } else {
            break;
          }
        }
      }
    }
  }
  pastenewcell();
}

function moveLeft() {
  var i, j;
  var col;
  for(i = 0; i < size; i++) {
    for(j = 1; j < size; j++) {
      if(cells[i][j].value) {
        col = j;
        while (col - 1 >= 0) {
          if (!cells[i][col - 1].value) {
            cells[i][col - 1].value = cells[i][col].value;
            cells[i][col].value = 0;
            col--;
          } else if (cells[i][col].value == cells[i][col - 1].value) {
            cells[i][col - 1].value *= 2;

            cells[i][col].value = 0;
            break;
          } else {
            break;
          }
        }
      }
    }
  }
  pastenewcell();
}

function moveRight () {
  var i, j;
  var col;
  for(i = 0; i < size; i++) {
    for(j = size - 2; j >= 0; j--) {
      if(cells[i][j].value) {
        col = j;
        while (col + 1 < size) {
          if (!cells[i][col + 1].value) {
            cells[i][col + 1].value = cells[i][col].value;
            cells[i][col].value = 0;
            col++;
          } else if (cells[i][col].value == cells[i][col + 1].value) {
            cells[i][col + 1].value *= 2;

            cells[i][col].value = 0;
            break;
          } else {
            break;
          }
        }
      }
    }
  }
  pastenewcell();
}
