const subjects = {
    1: ["EM-1", "Chemistry", "Mechanics", "C", "WorkShop", "Che-lab", "Mech Lab"],
    2: ["Em-2", "Physics", "Graphic", "CS", "EEE", "Phy-lab", "Grap-lab", "cs lab", "Seminar"],
    3: ["EM-3", "IPC", "CAO", "OOP-c++", "DSA", "OOP Lab", "DSA Lab", "Seminar-1"],
    4: ["OB", "Pro.&sat.", "Dis. Math", "DAA", "Web-Tech", "DAA-LAB", "Web-Lab", "Seminar-2"]
};

const credits = {
    1: [4, 4, 3, 3, 2, 1, 1],
    2: [4, 4, 2, 2, 2, 1, 2, 1, 1],
    3: [4, 2, 4, 4, 4, 1, 1, 2],
    4: [3, 4, 4, 4, 3, 1, 1, 2]
};

const gradeToPoint = (grade) => {
    switch (grade.toUpperCase()) {
        case "EX": return 10.0;
        case "AA": return 9.0;
        case "AB": return 8.5;
        case "BB": return 8.0;
        case "BC": return 7.5;
        case "CC": return 7.0;
        case "CD": return 6.5;
        case "DD": return 6.0;
        case "DE": return 5.5;
        case "EE": return 5.0;
        case "FF": return 0.0;
        default: return 0.0;
    }
};

const calculateCGPA = () => {
    let selectedSemester = document.getElementById('semester').value;
    let totalPoints = 0.0;
    let totalCredits = 0;

    if (selectedSemester === 'all') {
        // Loop through all semesters
        Object.keys(subjects).forEach(sem => {
            subjects[sem].forEach((subject, index) => {
                let grade = document.getElementById(`grade-${sem}-${index}`).value;
                totalPoints += gradeToPoint(grade) * credits[sem][index];
                totalCredits += credits[sem][index];
            });
        });
    } else {
        // Calculate for the selected semester only
        subjects[selectedSemester].forEach((subject, index) => {
            let grade = document.getElementById(`grade-${selectedSemester}-${index}`).value;
            totalPoints += gradeToPoint(grade) * credits[selectedSemester][index];
            totalCredits += credits[selectedSemester][index];
        });
    }

    let cgpa = totalPoints / totalCredits;
    document.getElementById('result').innerHTML = `<h3>Your CGPA is: ${cgpa.toFixed(2)}</h3>`;
};

document.getElementById('semester').addEventListener('change', function() {
    let selectedSemester = this.value;
    let subjectsDiv = document.getElementById('subjects');
    subjectsDiv.innerHTML = '';

    if (selectedSemester === 'all') {
        let table = '<div class="table-responsive"><table class="table table-bordered"><thead><tr><th>Semester</th>';
        let maxSubjects = Math.max(...Object.keys(subjects).map(sem => subjects[sem].length));
        for (let i = 0; i < maxSubjects; i++) {
            table += `<th>Subject ${i + 1}</th>`;
        }
        table += '</tr></thead><tbody>';

        Object.keys(subjects).forEach(sem => {
            table += `<tr><td>Semester ${sem}</td>`;
            subjects[sem].forEach((subject, index) => {
                table += `
                    <td>
                        <label for="grade-${sem}-${index}" class="form-label">${subject}</label>
                        <input type="text" class="form-control" id="grade-${sem}-${index}" required>
                    </td>
                `;
            });
            table += '</tr>';
        });

        table += '</tbody></table></div>';
        subjectsDiv.innerHTML = table;
    } else {
        subjects[selectedSemester].forEach((subject, index) => {
            subjectsDiv.innerHTML += `
                <div class="mb-3">
                    <label for="grade-${selectedSemester}-${index}" class="form-label">${subject}</label>
                    <input type="text" class="form-control" id="grade-${selectedSemester}-${index}" required>
                </div>
            `;
        });
    }
});

document.getElementById('semester').dispatchEvent(new Event('change'));
