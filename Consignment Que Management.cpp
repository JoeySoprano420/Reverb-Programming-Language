// Add consignments to queue
queue.add(myTask);
queue.add(anotherTask);

// Check consignment status
queue.status(myTask); // Returns status such as 'queued', 'running', 'completed'

// Cancel or modify a consignment in the queue
queue.modify(myTask, { priority: "low" });
queue.cancel(anotherTask);
