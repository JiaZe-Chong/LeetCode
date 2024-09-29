/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix: number[][]): void {
    const rows = matrix.length;
    const cols = matrix[0].length;
    let firstRowZero = false;
    let firstColZero = false;

    // Check if the first row needs to be zeroed
    for (let j = 0; j < cols; j++) {
        if (matrix[0][j] === 0) {
            firstRowZero = true;
            break;
        }
    }

    // Check if the first column needs to be zeroed
    for (let i = 0; i < rows; i++) {
        if (matrix[i][0] === 0) {
            firstColZero = true;
            break;
        }
    }

    // Use the first row and first column to mark zero rows and columns
    for (let i = 1; i < rows; i++) {
        for (let j = 1; j < cols; j++) {
            if (matrix[i][j] === 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeros based on the first row and first column
    for (let i = 1; i < rows; i++) {
        if (matrix[i][0] === 0) {
            for (let j = 1; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (let j = 1; j < cols; j++) {
        if (matrix[0][j] === 0) {
            for (let i = 1; i < rows; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set the first row and first column to zero if needed
    if (firstRowZero) {
        for (let j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColZero) {
        for (let i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
};