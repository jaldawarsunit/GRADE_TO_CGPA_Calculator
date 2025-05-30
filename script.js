const subjects = {
  1: ["EM-1", "Chemistry", "Mechanics", "C", "WorkShop", "Che-lab", "Mech Lab"],
  2: ["Em-2", "Physics", "Graphic", "CS", "EEE", "Phy-lab", "Grap-lab", "cs lab", "Seminar"],
  3: ["EM-3", "IPC", "CAO", "OOP-c++", "DSA", "OOP Lab", "DSA Lab", "Seminar-1"],
  4: ["OB", "Pro.&sat.", "Dis. Math", "DAA", "Web-Tech", "DAA-LAB", "Web-Lab", "Seminar-2"],
  5: ["SE", "CNIP", "ITSM", "JAVA", "CNIP-Lab", "SE & JV LAB", "Mini-project-1"]
};

const credits = {
  1: [4, 4, 3, 3, 2, 1, 1],
  2: [4, 4, 2, 2, 2, 1, 2, 1, 1],
  3: [4, 2, 4, 4, 4, 1, 1, 2],
  4: [3, 4, 4, 4, 3, 1, 1, 2],
  5: [4, 4, 3, 3, 1, 2, 4]
};

const gradeToPoint = grade => {
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

const populateSubjects = () => {
  let selectedSemester = document.getElementById('semester').value;
  let subjectsDiv = document.getElementById('subjects');
  subjectsDiv.innerHTML = '';

  const gradeOptions = ["EX", "AA", "AB", "BB", "BC", "CC", "CD", "DD", "DE", "EE", "FF"];

  if (selectedSemester === 'all') {
    Object.keys(subjects).forEach(sem => {
      let semHeader = document.createElement('h5');
      semHeader.textContent = `Semester ${sem}`;
      semHeader.classList.add('mt-3', 'text-primary', 'fw-bold');
      subjectsDiv.appendChild(semHeader);

      subjects[sem].forEach((subject, index) => {
        let div = document.createElement('div');
        div.classList.add('mb-2');
        div.innerHTML = `
          <label class="form-label">${subject}</label>
          <select id="grade-${sem}-${index}" class="form-select">
            <option value="">Select Grade</option>
            ${gradeOptions.map(grade => `<option value="${grade}">${grade}</option>`).join('')}
          </select>
        `;
        subjectsDiv.appendChild(div);
      });
    });
  } else {
    subjects[selectedSemester].forEach((subject, index) => {
      let div = document.createElement('div');
      div.classList.add('mb-3');
      div.innerHTML = `
        <label class="form-label">${subject}</label>
        <select id="grade-${selectedSemester}-${index}" class="form-select">
          <option value="">Select Grade</option>
          ${gradeOptions.map(grade => `<option value="${grade}">${grade}</option>`).join('')}
        </select>
      `;
      subjectsDiv.appendChild(div);
    });
  }
};

const calculateCGPA = () => {
  let selectedSemester = document.getElementById('semester').value;
  let totalPoints = 0;
  let totalCredits = 0;

  if (selectedSemester === 'all') {
    Object.keys(subjects).forEach(sem => {
      subjects[sem].forEach((subject, index) => {
        let grade = document.getElementById(`grade-${sem}-${index}`).value;
        if (grade) {
          totalPoints += gradeToPoint(grade) * credits[sem][index];
          totalCredits += credits[sem][index];
        }
      });
    });
  } else {
    subjects[selectedSemester].forEach((subject, index) => {
      let grade = document.getElementById(`grade-${selectedSemester}-${index}`).value;
      if (grade) {
        totalPoints += gradeToPoint(grade) * credits[selectedSemester][index];
        totalCredits += credits[selectedSemester][index];
      }
    });
  }

  if (totalCredits === 0) {
    document.getElementById('result').innerHTML = `<h3 class="text-danger">Please fill in grades!</h3>`;
    return;
  }

  let cgpa = totalPoints / totalCredits;
  document.getElementById('result').innerHTML = `<h3>Your CGPA is: ${cgpa.toFixed(2)}</h3>`;
};

document.getElementById('semester').addEventListener('change', populateSubjects);
document.addEventListener('DOMContentLoaded', populateSubjects);
