C++
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

// API Specification for Responsive Data Pipeline Dashboard

// Dashboard Configuration
struct DashboardConfig {
    std::string title;
    std::vector<std::string> columns;
    std::vector<std::string> rows;
};

// Data Point
struct DataPoint {
    std::string id;
    std::string value;
    std::string timestamp;
};

// Data Pipeline
struct DataPipeline {
    std::string id;
    std::vector<DataPoint> dataPoints;
};

// Dashboard API
class DashboardAPI {
public:
    // Initialize dashboard with configuration
    void initDashboard(DashboardConfig config);

    // Add data pipeline to dashboard
    void addDataPipeline(DataPipeline pipeline);

    // Get data points for a specific column and row
    std::vector<DataPoint> getDataPoints(std::string column, std::string row);

    // Get all data points for a specific pipeline
    std::vector<DataPoint> getAllDataPoints(std::string pipelineId);

    // Update data point value
    void updateDataPointValue(std::string dataPointId, std::string newValue);

    // Delete data point
    void deleteDataPoint(std::string dataPointId);

private:
    std::map<std::string, DataPipeline> pipelines;
    DashboardConfig config;
};

// Dashboard View
class DashboardView {
public:
    // Render dashboard with data
    void renderDashboard(DashboardAPI api);

    // Update dashboard view when data changes
    void updateDashboardView(std::vector<DataPoint> updatedDataPoints);

private:
    // Dashboard HTML template
    std::string templateHTML;
};

int main() {
    // Create dashboard API instance
    DashboardAPI api;

    // Initialize dashboard configuration
    DashboardConfig config;
    config.title = "Responsive Data Pipeline Dashboard";
    config.columns = {"Column 1", "Column 2", "Column 3"};
    config.rows = {"Row 1", "Row 2", "Row 3"};

    // Initialize dashboard
    api.initDashboard(config);

    // Add data pipelines to dashboard
    DataPipeline pipeline1;
    pipeline1.id = "Pipeline 1";
    pipeline1.dataPoints = {{ "DataPoint 1-1", "Value 1-1", "2022-01-01" }, { "DataPoint 1-2", "Value 1-2", "2022-01-02" }};
    api.addDataPipeline(pipeline1);

    DataPipeline pipeline2;
    pipeline2.id = "Pipeline 2";
    pipeline2.dataPoints = {{ "DataPoint 2-1", "Value 2-1", "2022-01-03" }, { "DataPoint 2-2", "Value 2-2", "2022-01-04" }};
    api.addDataPipeline(pipeline2);

    // Create dashboard view instance
    DashboardView view;

    // Render dashboard with data
    view.renderDashboard(api);

    return 0;
}